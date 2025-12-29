#include<bits/stdc++.h>
using namespace std;
//where any of ui or vi should be ancestor of the other
//ans = 17 //see input next file
int n,m;
vector<vector<int>> g;
vector<int> val;

int ans=0;

void dfs(int nn, int pp, int minSeen, int maxSeen){//maintain a running min,max at every node
    cout<<nn<<" "<<pp<<" "<<minSeen<<" "<<maxSeen<<"\n";
    if(pp!=-1)
        ans = max({ ans, abs(minSeen-val[nn]), abs(maxSeen-val[nn]) });
    for(auto v:g[nn]){
        if(v==pp)continue;
        dfs( v, nn, min(minSeen,val[nn]), max(maxSeen,val[nn]) );
    }
}

int main(){
    cin>>n>>m;
    g.resize(n+1);
    val.resize(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1,1e9,-1e9);
    cout<<"ans = "<<ans;
    return 0;
}