#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;

void dfs(int node){
    vis[node]=1;
    for(auto v : g[node]){
        if(!vis[node]){
            dfs(v);
        }
    }
}

int dp[100100];
int rec(int node){
    if(dp[node]!=-1)return dp[node];
    int ans=1;
    for(auto v: g[node]){
        ans=max(1,1+rec(v));
    }
    return dp[node]=ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,rec(i));
    }
    cout<<ans;
    return 0;
}
