// #include <bits/stdc++.h>
// using namespace std;
// //count of cc_nums and size of each cc present in the graph
// vector<vector<int>> g;
// vector<int> vis;

// int cc_num;//count of cc_nums
// int cmp_size;//size of each cc present in the graph

// void dfs(int node){
//     vis[node] = 1;
//     cmp_size++;
//     for(auto neigh : g[node]){
//         if(!vis[neigh]){
//             dfs(neigh);
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
    
//     int n, m;
//     cin >> n >> m;
//     g.resize(n+1);
//     vis.assign(n+1, 0);

//     for(int i = 1; i <= m; i++){
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     // Preprocess all components
//     for(int i = 1; i <= n; i++){
//         if(!vis[i]){
//             cc_num++;
//             cmp_size=0;
//             dfs(i);
//             cout<<cmp_size<<" ";
//         }
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;

vector<int>cc_id_vec;//stores ids of each node
unordered_map<int,int> cmp_size_vec;//stores size of each id // cuz its not already initialized


void dfs(int node, int cc_id){
    vis[node] = 1;
    cc_id_vec[node]=cc_id;//she merged them//har node ko uska ek comp no./id is getting assigned
    cmp_size_vec[cc_id]++;
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
    cc_id_vec.resize(n+1);//har ek node ka ek id to which cc they belong
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
    int x,y;
    cin>>x>>y;
    if(cc_id_vec[x]==cc_id_vec[y]){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    int a;
    cin>>a;
    int id_a=cc_id_vec[a];
    cout<<cmp_size_vec[id_a];//gives the size of the cc in which node a is present
    return 0;
}
