#include <bits/stdc++.h>
using namespace std;

//cycle detection in directed graph

vector<vector<int>> g;
vector<int> color;
int have_cycle=0;


void dfs(int node){
    color[node]=1;
    for(auto neigh : g[node]){
        if(color[neigh]==1){
            //node to v is : the edge is forward edge // not yet visited
            color[neigh]=2;
            dfs(neigh);
        }else if(color[neigh]==2){
            //node to v is : the edge is back edge 
            have_cycle=1;
        }else if(color[neigh]==3){
            //the edge is cross edge
            //not useful ese hi tha ye to 
        }
    }
    color[node]=3;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    color.assign(n+1,1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        //cuz it is directed graph
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(color[i]==1){
            dfs(i);
        }
    }
    if(have_cycle)cout<<"Yes";
    else cout<<"No";
    return 0;
}
