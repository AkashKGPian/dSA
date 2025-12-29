#include <bits/stdc++.h>
using namespace std;

//find the no. of edge

vector<vector<int>> g;
vector<int> visited;

int cmp_size=0;//connected component me ek component ka size 

void DFS(int node){
    visited[node]=1;
    cmp_size++;
    for(auto neigh : g[node]){
        if(!visited[neigh]){
            DFS(neigh);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;

    g.resize(n+1);
    visited.assign(n+1,0);//o here means its not visited yet

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //getting connectedcompontents count
    vector<int> cc_size_vec;
    int cc_num=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cc_num++;
            cmp_size=0;
            DFS(i);
            cc_size_vec.push_back(cmp_size);
        }
    }
    cout<<"---------\n";
    cout<<cc_num<<"\n";
    for(auto elem : cc_size_vec)cout<<elem<<" ";
    cout<<"\n";

    long long sum=0;
    long long ans=0;
    for(int elem : cc_size_vec){
        ans+=elem*sum;
        sum+=elem; 
    }
    cout<<ans;
    return 0;
}
