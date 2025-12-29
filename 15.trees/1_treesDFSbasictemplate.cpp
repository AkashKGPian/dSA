#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;

vector<int> par;
vector<int> depth;

void dfs(int nn, int pp, int dd){
    par[nn]=pp;
    depth[nn]=dd;
    cout<<nn<<" "<<pp<<" "<<dd<<"\n";
    for(auto v:g[nn]){
        if(v==pp)continue;
        dfs(v,nn,dd+1);
    }
}

int main(){
    cin>>n>>m;
    g.resize(n+1);
    par.resize(n+1);
    depth.resize(n+1);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1,0);
    return 0;
}