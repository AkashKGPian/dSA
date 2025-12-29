#include <bits/stdc++.h>
using namespace std;
//need an extra parent and anycycle vector
// 5 5
// 1 2
// 2 3
// 3 4
// 4 5
// 5 2

vector<vector<int>> g;
vector<int> color;
vector<int> any_cycle;
vector<int> parent;
int have_cycle=0;

void dfs(int node,int p){
    color[node]=2;
    parent[node]=p;
    for(auto neigh : g[node]){
        if(color[neigh]==1){
            //node to v is : the edge is forward edge // not yet visited
            color[neigh]=2;
            dfs(neigh,node);
        }else if(color[neigh]==2){
            //node to v is : the edge is back edge 
            cout<<"HIT : "<<node <<"\n";
            if(have_cycle==0){
                int temp = node;
                while(temp!=neigh){
                    any_cycle.push_back(temp);
                    temp=parent[temp];
                }
                any_cycle.push_back(temp);
                reverse(any_cycle.begin(),any_cycle.end());
            }
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
    parent.assign(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        //cuz it is directed graph
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(color[i]==1){
            dfs(i,0);
        }
    }
    for(auto v : any_cycle){
        cout<<v<<" ";
    }
    return 0;
}
