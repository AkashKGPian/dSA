#include <bits/stdc++.h>
using namespace std;
//given a DAG find the topological order and if there is cycle present 
//and thereby say its not a dag

int n,m;
vector<vector<int>> g;
vector<int> indeg;

vector<int> topo;


void kahn(){
    queue<int> q;
    //push all nodes with indegree 0 in the queue
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)q.push(i);
    }
    //keep on popping from the queue and reducing the indegree of its neighbours
    while(!q.empty()){
        int curr = q.front(); q.pop();
        
        topo.push_back(curr);
        for(auto neigh : g[curr]){
            indeg[neigh]--;
            if(indeg[neigh]==0){
                q.push(neigh);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    g.resize(n+1);
    indeg.assign(n+1,0);

    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        indeg[y]++;
    }
    //u never called the function
    kahn();

    if(topo.size()!=n){
        cout<<"There is a cycle present in the graph. Hence its not a DAG"<<"\n";
    }else{
        for(auto v : topo){
            cout<<v<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
