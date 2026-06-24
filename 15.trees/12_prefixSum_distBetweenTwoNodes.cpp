#include<bits/stdc++.h>
using namespace std;
using state = pair<int,int>;
#define F first
#define S second

// 5
// 4 5
// 1 2 3
// 1 3 2
// 2 4 4
// 2 5 6


int n;
int p,q;
vector<vector<state>> g;
vector<int> par;
int prefix[1000100];

int nextPar[1000100][20];
vector<int> depth;

void dfs(int nn, int pp, int dd){
    nextPar[nn][0]=pp;//next is in context with storing 2^ith elem 
    depth[nn]=dd;
    
    for(int i=1;i<20;i++){
        nextPar[nn][i]=nextPar[nextPar[nn][i-1]][i-1];
    }
    
    for(auto v:g[nn]){
        if(v.F==pp)continue;
        dfs(v.F,nn,dd+1);
    }
}

int lca(int u, int v){
    if(depth[u]<depth[v]) swap(u,v);
    for(int i=19;i>=0;i--){
        if((depth[u]-depth[v])&(1<<i)){
            u=nextPar[u][i];
        }
    }
    if(u==v)return u;
    for(int i=19;i>=0;i--){
        if(nextPar[u][i]!=nextPar[v][i]){
            u=nextPar[u][i];
            v=nextPar[v][i];
        }
    }
    return nextPar[u][0];
}

void dfsPrefix(int nn, int pp, int val){
    par[nn]=pp;
    prefix[nn] = val + prefix[pp];//prefix stores the dist of that nn from the rooted node
    
    for(auto v:g[nn]){
        if(v.F==pp)continue;
        dfsPrefix(v.F,nn,v.S);
    }
}

int getSum(int u, int v){
    return prefix[u]+prefix[v]-2*prefix[lca(u,v)];
}

int main(){
    cin>>n;
    cin>>p>>q;
    g.resize(n+1);
    par.resize(n+1);
    depth.resize(n+1);
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dfs(1,0,0);
    dfsPrefix(1,0,0);
    cout<<getSum(p,q);
    return 0;
}