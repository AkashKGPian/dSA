#include<bits/stdc++.h>
using namespace std;
//lowest common ancestor

int n;
int u, v;
vector<vector<int>> g;
int par[1000100][20];
vector<int> depth;

void dfs(int nn, int pp, int dd){
    par[nn][0]=pp;//base case
    depth[nn]=dd;
    //caching the log scale 
    for(int i=1;i<20;i++){
        par[nn][i] = par[par[nn][i-1]][i-1];
    }
    for(auto v:g[nn]){
        if(v==pp)continue;
        dfs(v,nn,dd+1);
    }
}

int lca(int u, int v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    //make their depths equal
    for(int i=19;i>=0;i--){
        if((depth[u]-depth[v])&(1<<i)){
            u=par[u][i];
        }
    }
    if(u==v)return u;
    //raise till not equal
    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}

int main(){
    cin>>n;
    cin >> u >> v;
    g.resize(n+1);
    depth.resize(n+1);
    
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);//have to take parent as 0 for the rooted node
    // Example query
    cout << lca(u, v) << endl;
    return 0;
}