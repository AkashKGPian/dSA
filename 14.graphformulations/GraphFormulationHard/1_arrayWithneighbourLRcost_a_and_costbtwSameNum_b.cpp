#include<bits/stdc++.h>
using namespace std;

//how to take input
//normal dijktra after making graph
//question is given an array of n numbers - with same no. are connected with a cost b
// and neighbour(L,R) numbers are connected with cost a

vector<vector<pair<int,int>>> g;//node, cost

int main(){
    int n;
    int a,b;
    cin>>n>>a>>b;

    map<int, vector<int>> mp;// num, places that num occured
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        mp[x].push_back(i);
    }
    g.resize(n+mp.size()+1);
    //just the left and right connections // cost a
    for(int i=1;i<n;i++){
        g[i].push_back({i+1,a});
        g[i+1].push_back({i,a});
    }
    int Dnode=n+1;//new supernode created
    for(auto &v:mp){
        for(auto u:v.second){
            g[Dnode].push_back({u,b});//supernode(Dnode)-->node u cost = b
            g[u].push_back({Dnode,0});
        }
        Dnode++;
    }
    //graph bangaya
    //run dijktra
    return 0;
}