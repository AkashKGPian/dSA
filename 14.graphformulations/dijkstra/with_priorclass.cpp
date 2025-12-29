#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define state pair<lli,int> //  wt_OR_dist, node  // no use of prioritize_class
#define F first
#define S second
#define MP make_pair

int n,m;
vector<state> g[100100];
lli dist[100100];
int vis[100100];

void dijktra(int sc){
    for(int i=1;i<=n;i++){
        dist[i]=1e18;
        vis[i]=0;
    }
    dist[sc]=0;
    priority_queue<state> pq;
    pq.push(MP(-0,sc));
    
    while(!pq.empty()){
        state curr = pq.top(); pq.pop();
        int node = curr.S;
        if(vis[node])continue;
        vis[node]=1;
        
        for(auto v : g[node]){
            int neigh = v.S;
            int wt_OR_dist = v.F;
            if(dist[neigh]>dist[node]+wt_OR_dist){
                dist[neigh]=dist[node]+wt_OR_dist;
                pq.push(MP(-dist[neigh], neigh));
            }
        }
    }
    
}

void solve(){
    cin>>n>>m;
    // g.resize(n+1,0);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;//dist , node since no prioritize_class
        g[a].push_back({c,b});
        g[b].push_back({c,a});
    }
    dijktra(1);
}

int main(){
    solve();
    return 0;
}