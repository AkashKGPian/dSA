#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;
vector<int>cc_id_vec;


void dfs(int node, int cc_id){
    vis[node] = 1;
    cc_id_vec[node]=cc_id;
    for(auto neigh : g[node]){
        if(!vis[neigh]){
            dfs(neigh,cc_id);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    vis.assign(n+1, 0);

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Preprocess all components
    int cc_id=0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cc_id++;
            dfs(i,cc_id);
        }
    }
    return 0;
}
