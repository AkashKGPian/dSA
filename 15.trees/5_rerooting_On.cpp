#include<bits/stdc++.h>
using namespace std;
//o(n2)
int n,m;
vector<vector<int>> g;
vector<int> depth;
vector<int> anslength;
vector<int> sz;//size of a subtree for a particular node

void dfs(int nn, int pp, int dd){//maintain a running min,max at every node
    depth[nn]=dd;
    sz[nn]=1;
    for(auto v:g[nn]){
        if(v==pp)continue;
        dfs(v,nn,dd+1);
        sz[nn]+=sz[v];
    }
}

void dfs2(int nn, int pp){
    for(auto v:g[nn]){
        if(v==pp)continue;
        anslength[v] = anslength[nn]+n-2*sz[v];
        dfs2(v,nn);
    }
}

int main(){
    cin>>n>>m;
    g.resize(n+1);
    sz.resize(n+1);
    depth.resize(n+1);
    anslength.assign(n+1,0);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1,0);
    for(int i=1;i<=n;i++){
        anslength[1]+=depth[i];
    }
    dfs2(1,-1);
    for(int i=1;i<=n;i++){
        cout<<i<<" : "<<anslength[i]<<"\n";
    }
    return 0;
}