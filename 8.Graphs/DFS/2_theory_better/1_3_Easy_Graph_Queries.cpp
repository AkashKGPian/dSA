#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;

vector<int> cc_id;
unordered_map<int,int> cc_id_size;

void dfs(int node, int id){
    vis[node] = 1;
    cc_id[node]=id;//assigned id to each node
    cc_id_size[id]++;//inc the count of each id for each dfs call = size of a particular cc
    for(auto neigh : g[node]){
        if(!vis[neigh]){
            dfs(neigh, id);
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
    cc_id.resize(n+1);

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Preprocess all components
    int id=0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            id++;
            dfs(i,id);
        }
    }

    while(q--){
        int a;
        cin >> a;
        if(a == 1){
            int x;
            cin >> x;
            //size of the connected components containing node X.
            int id_x=cc_id[x];
            cout<<cc_id_size[id_x]<<"\n";
        } else if(a == 2){
            int x, y;
            cin >> x >> y;
            if(cc_id[x]==cc_id[y]){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }

    return 0;
}
