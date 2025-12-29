#include <bits/stdc++.h>
using namespace std;

//are x and y in the same comp

vector<vector<int>> g;
vector<int> visited;
vector<int> comp_num;//kaunsa wala comp hai ? har comp ko ek no. assign kar diya ja rha hai

void DFS(int node, int comp_cc){
    visited[node]=1;
    comp_num[node]=comp_cc;
    for(auto neigh : g[node]){//iterate on neighbours of node // run the no. of times = count of cc
        if(!visited[neigh]){
            DFS(neigh,comp_cc);
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

    comp_num.assign(n+1,0);
    g.resize(n+1);
    visited.assign(n+1,0);//0 here means its not visited yet

    for(int i=0;i<m;i++){//taking edge input as a node pair
        int a,b;
        cin>>a>>b;
        //adjecency list
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //time complexity o(q*(n+m)) very high tle

    // int q;
    // cin>>q;
    // while(q--){
    //     int x,y;
    //     cin>>x>>y;
    //     DFS(x);
    //     if(visited[y]==1){
    //         cout<<"Yes\n";
    //     }else{
    //         cout<<"No\n";
    //     }
    //     visited.assign(n+1,0);
    // }

    int comp_cc=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            comp_cc++;
            DFS(i,comp_cc);
        }
    }
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(comp_num[x]==comp_num[y]){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
