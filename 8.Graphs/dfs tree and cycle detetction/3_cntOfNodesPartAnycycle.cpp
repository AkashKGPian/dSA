#include <bits/stdc++.h>
using namespace std;
//what is the cnt of nodes which are part of any cycle
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

vector<int> cnt_cycle;
vector<int> prefixorder;
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
            cnt_cycle[node]++;
            cnt_cycle[parent[neigh]]--;
            have_cycle=1;
        }else if(color[neigh]==3){
            //the edge is cross edge
            //not useful ese hi tha ye to 
        }
    }
    color[node]=3;
    //the order in which a node is marked 3 we want prefixorder to have the same order
    prefixorder.push_back(node);
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
    cnt_cycle.assign(n+1,0);
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
    cout<<"\n";
    for(auto v : prefixorder){
        cnt_cycle[parent[v]]+=cnt_cycle[v];
    }
    int cntNode=0;//nodes which are part of any cycle
    for(int i=1;i<=n;i++){
        if(cnt_cycle[i]>0){
            cntNode++;
        }
    }
    cout<<cntNode<<"\n";
    return 0;
}
