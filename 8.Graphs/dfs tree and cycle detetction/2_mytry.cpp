#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col;
vector<int>parent;
vector<int>any_cycle;

bool is_cycle = 0;

void dfs(int node,int par){
    col[node]=2;
    parent[node]=par;
    for(auto neigh : g[node]){
        if(col[neigh]==1){
            //not visited
            dfs(neigh,node);
        }else if(col[neigh]==2){
            //cuz doing it for all the cycle in not within the range of linear time complexity 
            // thus we will do it for one
            if(is_cycle==0){
                cout<<"Hit : \n"<<node;
                int temp = node;
                while(temp!=neigh){
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }
                any_cycle.push_back(temp);
                reverse(any_cycle.begin(),any_cycle.end());
            }
            is_cycle=1;
        }else if(col[neigh]==3){
            //not important
        }
        col[neigh]=3; 
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
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        //cuz directed graph
    }
    for(int i=1;i<=n;i++){
        if(col[i]==1){
            dfs(i,-1);
        }
    }
    if(is_cycle)cout<<"Yes\n";
    else cout<<"No\n";
    
    for(auto v : any_cycle){
        cout<<v<<" ";
    }
    
    return 0;
}