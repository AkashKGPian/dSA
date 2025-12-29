#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col;
vector<int>parent;

bool is_cycle = 0;

void dfs(int node, int par){
    col[node]=2;
    parent[node]=par;
    for(auto neigh : g[node]){
        // wrong - if(neigh==node)continue;
        //since it goes both way in the adjecency list every node and neigh will together form a cycle
        if(neigh==parent[node])continue;
        if(col[neigh]==1){
            //not visited
            dfs(neigh,node);
        }else if(col[neigh]==2){
            is_cycle=1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,1);//1 means unvisted nodes
    parent.assign(n+1,-1);

    map<pair<int,int>,int> edgecnt;
    for(int i=1;i<=m;i++){
        //undirected graph
        int x,y;
        cin>>x>>y;
        if(x==y){
            // Ignore self-loop
            continue;
        }

        if(x>y) swap(x, y); // Normalize for undirected edge
        edgecnt[make_pair(x, y)]++;

        if(edgecnt[make_pair(x, y)] == 1){//take input only once
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        if(col[i]==1){
            dfs(i,-1);
        }
    }
    if(is_cycle)cout<<"YES";
    else cout<<"NO";
    return 0;
}