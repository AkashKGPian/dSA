#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;

bool is_bipartite=1;
vector<int> col;

void dfs(int node, int cur_col){
    vis[node] = 1;
    col[node]=cur_col;
    for(auto neigh : g[node]){
        if(!vis[neigh]){
            dfs(neigh, 3-cur_col);
        }else{
            if(col[neigh]==col[node]){
                is_bipartite=0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    g.resize(n+1);
    vis.assign(n+1, 0);
    col.resize(n+1);

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    is_bipartite=1;//assume that it is bipartitie
    // Preprocess all components
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i,1);
        }
    }
    return 0;
}
