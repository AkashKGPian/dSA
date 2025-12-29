#include <bits/stdc++.h>
using namespace std;

//are x and y in the same comp

vector<vector<int>> g;
vector<int> visited;
vector<int> col;//kaunsa wala comp hai ? har comp ko ek col assign kar diya ja rha hai

int is_bipartite=1;//assume ki vo hai

void DFS(int node, int cur_col){
    visited[node]=1;
    col[node]=cur_col;
    for(auto neigh : g[node]){//iterate on neighbours of node // run the no. of times = count of cc
        if(!visited[neigh]){
            DFS(neigh,3-cur_col);
        }else{
            if(col[neigh]==col[node]){
                is_bipartite=0;
            }
        }
    }
    return ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;//nodes and edges resp

    col.assign(n+1,0);
    g.resize(n+1);
    visited.assign(n+1,0);//0 here means its not visited yet

    for(int i=0;i<m;i++){//taking edge input as a node pair
        int a,b;
        cin>>a>>b;
        //adjecency list
        g[a].push_back(b);
        g[b].push_back(a);
    }

    is_bipartite=1;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            DFS(i,1);
        }
    }
    cout<<"-------\n";
    if(is_bipartite){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<col[i]<<"\n";
    }
    return 0;
}
