#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;

void dfs(int node){
    vis[node]=1;
    for(auto neigh : g[node]){
        if(!vis[neigh]){
            dfs(neigh);
        }
    }
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
        g[b].push_back(a);
    }
    int cc_num=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cc_num++;
            dfs(i);
        }
    }
    cout<<cc_num-1<<"\n";
    return 0;
}
