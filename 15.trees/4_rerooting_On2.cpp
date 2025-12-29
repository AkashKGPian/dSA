#include<bits/stdc++.h>
using namespace std;
//o(n2)
int n,m;
vector<vector<int>> g;
vector<int> val;
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

int main(){
    cin>>n>>m;
    g.resize(n+1);
    val.resize(n+1);
    sz.resize(n+1);
    depth.resize(n+1);
    anslength.assign(n+1,0);
    
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int root = 1; root<=n; root++){
        dfs(root,-1,0);
        for(auto v:depth){
            anslength[root]+=v;
        }
    }
    for(auto v:anslength){
        cout<<v<<"\n";
    }
    return 0;
}