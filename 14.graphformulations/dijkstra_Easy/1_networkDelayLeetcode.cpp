#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second 
class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> g;
    vector<int> dist, vis;

    void dijkstra(int k){
        vis=vector<int>(n+1,0);
        dist=vector<int>(n+1,1e9);

        priority_queue<pair<int,int>> pq;//wt, node
        dist[k]=0;
        pq.push({-0,k});

        while(!pq.empty()){
            pair<int,int> curr=pq.top(); pq.pop();
            int wt=-curr.f;

            if(vis[curr.s])continue;
            vis[curr.s]=1;

            for(auto neigh:g[curr.s]){
                if(!vis[neigh.s] && dist[neigh.s]>dist[curr.s]+neigh.f){
                    dist[neigh.s]=dist[curr.s]+neigh.f;
                    pq.push({-dist[neigh.s], neigh.s});
                }
            }
        }

    }
    int networkDelayTime(vector<vector<int>>& times, int input_n, int k) {
        n=input_n;
        g.resize(n+1);
        for(int i=0;i<times.size();i++){
            g[times[i][0]].push_back({times[i][2],times[i][1]});//{wt,node}
        }
        dijkstra(k);
        int minTime=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            minTime=max(minTime, dist[i]);
        }
        return minTime;
    }
};