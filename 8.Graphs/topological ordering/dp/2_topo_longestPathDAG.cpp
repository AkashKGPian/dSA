#include <bits/stdc++.h>
using namespace std;
//topological ordering in DAG
//directed

vector<vector<int>> g;
vector<int> vis;
vector<int> topo;

int dp[100100];

void dfs(int node){
    vis[node]=1;
    for(auto v : g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
    topo.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    // reverse(topo.begin(),topo.end());
    // for(auto v : topo){
    //     cout<<v<<" ";
    // }    
    int final=0;
    for(auto node:topo){
        int ans=1;
        for(auto v:g[node]){
            ans=max(ans,1+dp[v]);
        }
        dp[node]=ans;
        final=max(final,dp[node]);
    }
    cout<<final<<"\n";
    return 0;
}
