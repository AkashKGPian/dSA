#include<bits/stdc++.h>
using namespace std;

vector<int> vis;
vector<vector<int>> g;

int cnt;

void dfs(int node){
    vis[node]=1;
    for(auto neigh : g[node]){//iterate on neighbours of node // run the no. of times = count of cc
        cnt++;
        if(!vis[neigh]){
            dfs(neigh);
        }
    }
}


int main(){
    int n,m;//taking input=> node and edge
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1);
    for(int i=1;i<=m;i++){//taking edge input as a node pair
        int a,b;
        cin>>a>>b;
        //adjecency list
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // dfs(5);
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<vis[i]<<"\n";
    // }
    // dfs(1);
    // dfs(8);
    // cout<<"-------------\n";
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<visited[i]<<"\n";
    // }
    // cout<<cnt;
    
    // ------------------
    // here i is the node numbering
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt;
    return 0;
}