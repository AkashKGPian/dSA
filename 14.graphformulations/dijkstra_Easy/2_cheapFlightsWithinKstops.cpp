#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
using state=pair<pair<int,int>,int>;
class Solution {
public:
    int n;
    vector<vector<int>> vis, dist;
    vector<vector<pair<int,int>>> g;//wt, node

    void dijkstra(int src, int k){
        vis=vector<vector<int>>(n, vector<int>(k+2,0));//for k stops -> k+1 flights needed
        dist=vector<vector<int>>(n, vector<int>(k+2,1e9));

        priority_queue<state> pq;//{{wt,node},k}
        dist[src][0]=0;
        pq.push({{-0,src},0});
        while(!pq.empty()){
            state curr=pq.top(); pq.pop();

            if(vis[curr.f.s][curr.s])continue;
            vis[curr.f.s][curr.s]=1;

            for(auto neigh : g[curr.f.s]){
                int ns=curr.s+1;
                if(ns>k+1)continue;
                if(!vis[neigh.s][ns] && dist[neigh.s][ns]>dist[curr.f.s][curr.s]+neigh.f){
                    dist[neigh.s][ns]=dist[curr.f.s][curr.s]+neigh.f;
                    pq.push({{-dist[neigh.s][ns],neigh.s},ns});
                }
            }
        }
    }
    int findCheapestPrice(int input_n, vector<vector<int>>& flights, int src, int dst, int k) {
        n=input_n;
        g.resize(n);
        for(int i=0;i<flights.size(); i++){
            g[flights[i][0]].push_back({flights[i][2],flights[i][1]});//{wt, node}
        }
        dijkstra(src,k);
        int cheapMinPrice=1e9;
        bool flagDSTvis=0;
        for(int i=0;i<=k+1;i++){
            if(dist[dst][i]!=1e9) flagDSTvis=1;
            cheapMinPrice=min(cheapMinPrice, dist[dst][i]);
        }
        return (flagDSTvis)? cheapMinPrice:-1;
    }
};