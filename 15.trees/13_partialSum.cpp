#include<bits/stdc++.h>
using namespace std;

int n,q;
vector<vector<int>> g;
int par[1000100][20];
vector<int> depth;

vector<int> partial;

void dfs(int nn, int pp, int dd){
    par[nn][0]=pp;
    depth[nn]=dd;
    for(int i=1;i<=19;i++){
        par[nn][i]=par[par[nn][i-1]][i-1];
    }
    for(auto v:g[nn]){
        if(v==pp)continue;
        dfs(v,nn,dd+1);
    }
}

int lca(int u, int v){
    //u upar h v ke to swap
    if(depth[u]<depth[v]) swap(u,v);
    //jumps to make depth equal
    for(int i=19;i>=0;i--){
        u=par[u][i];
    }
    if(u==v)return u;
    //jump till par of u and v are not same
    for(int i=19;i>=0;i--){
        if((depth[u]-depth[v])&(1<<i)){
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}

void addX(int u, int v, int X){
    partial[u]+=X;
    partial[v]+=X;
    int lc = lca(u,v);
    partial[lc]-=X;
    partial[par[lc][0]]-=X;
}

void dfsPushAll(int nn, int pp){
    par[nn][0]=pp;
    for(auto v:g[nn]){
        if(v==pp)continue;
        dfsPushAll(v,nn);
    }
    partial[par[nn][0]]+=partial[nn];
}

int main(){
    cin>>n>>q;
    g.resize(n+1);
    partial.resize(n+1);
    depth.resize(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    while(q--){
        int u,v,X;
        cin>>u>>v>>X;
        addX(u,v,X);
    }
    dfsPushAll(1,0);

    for(auto v : partial){
        cout << v << "\n";
    }
    return 0;
}