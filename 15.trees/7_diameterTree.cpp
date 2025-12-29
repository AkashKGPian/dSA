#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> par;
vector<int> depth;

void dfs(int nn, int pp, int dd){
    depth[nn]=dd;
    par[nn]=pp;

    for(auto v:g[nn]){
        if(v==pp)continue;
        dfs(v,nn,dd+1);
    }
}

int main(){
    cin>>n;
    g.resize(n+1);
    par.resize(n+1);
    depth.resize(n+1);
    
    for(int i=1; i<n; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1,0);
    
    int maxChild=1;
    for(int j=2;j<=n;j++){
        if(depth[j]>depth[maxChild]){
            maxChild=j;
        }
    }
    
    dfs(maxChild,-1,0);
    maxChild=1;
    for(int j=2;j<=n;j++){
        if(depth[j]>depth[maxChild]){
            maxChild=j;
        }
    }
    cout<<depth-[maxChild];//diameter
    return 0;
}