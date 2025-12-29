#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;

vector<int> cc_id;
unordered_map<int,long long> cc_id_size;

void dfs(int node,int id){
    vis[node]=1;
    cc_id[node]=id;
    cc_id_size[id]++;
    for(auto neigh : g[node]){
        if(!vis[neigh]){
            dfs(neigh,id);
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
    cc_id.resize(n+1);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int id=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            id++;
            dfs(i,id);
        }
    }
    long long ans = 0;
    long long sum = n;
    // for (auto v : cc_id_size) {
    //     sum+=v.second;
    // }
    for(auto v : cc_id_size){
        ans+=v.second*(sum-v.second);
    }
    cout << ans/2;
    return 0;
}
