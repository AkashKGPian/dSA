#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> par;
vector<int> depth;
vector<int> noChild;
vector<int> isleaf;
vector<int> subTreeSZ;

void dfs(int nn, int pp, int dd){
    depth[nn]=dd;
    par[nn]=pp;
    subTreeSZ[nn]=1;
    for(auto v:g[nn]){
        if(v==pp)continue;
        noChild[nn]++;
        dfs(v,nn,dd+1);
        subTreeSZ[nn]+=subTreeSZ[v];
    }
    if(noChild[nn]==0) isleaf[nn]=1;
}

int main(){
    cin>>n;
    g.resize(n+1);
    par.resize(n+1);
    depth.resize(n+1);
    noChild.assign(n+1,0);
    isleaf.assign(n+1,0); 
    subTreeSZ.resize(n+1);
    
    for(int i=1; i<n; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1,0);
    return 0;
}