#include<bits/stdc++.h>
using namespace std;

int n,q;
vector<vector<int>> g;
vector<vector<int>> par;
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
        if((depth[u]-depth[v])&(1<<i)){
            u=par[u][i];
        }
    }
    if(u==v)return u;
    //jump till par of u and v are not same
    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]){
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
    for(auto v:g[nn]){
        if(v==pp)continue;
        dfsPushAll(v,nn);
    }
    partial[par[nn][0]]+=partial[nn];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        g.assign(n+1, {});
        partial.assign(n+1,0);
        depth.assign(n+1,0);
        par = vector<vector<int>>(n+1,vector<int>(20));
        
        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        cin>>q;
        dfs(1,0,0);
        while(q--){
            int u,v,X;
            cin>>u>>v>>X;
            addX(u,v,X);
        }
        dfsPushAll(1,0);
        for(int i=1;i<=n;i++){
            cout<<partial[i]<<" ";
        }
        cout << "\n";
    }
    return 0;
}