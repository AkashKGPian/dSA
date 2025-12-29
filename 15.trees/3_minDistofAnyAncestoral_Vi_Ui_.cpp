#include<bits/stdc++.h>
using namespace std;
// 10 9
// 3 5 7 2 9 5 10 20 6 11
// 1 2 
// 1 3
// 1 4
// 3 5
// 3 6
// 5 7
// 6 8
// 6 9
// 6 10


int n,m;
vector<vector<int>> g;
vector<int> val;

multiset<int> parvals;
int ans = 1e9;

int getClosestDist(int x){
    int curr = 1e9;
    //uss element ke ek just aage wala ya wo kudh if present more than once
    auto it = parvals.lower_bound(x);
    if(it!=parvals.end()){
        curr = min(curr,*it-x);
    }
    //dist from an element just behind it
    if(it!=parvals.begin()){
        curr = min(curr,x - *(--it));
    }
    return curr;
}

void dfs(int nn, int pp){//maintain a running min,max at every node
    
    ans = min(ans,getClosestDist(val[nn]));
    
    parvals.insert(val[nn]);
    for(auto v:g[nn]){
        if(v==pp)continue;
        dfs(v,nn);
    }
    parvals.erase(parvals.find(val[nn]));
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
    dfs(1,-1);
    cout<<"ans = "<<ans;
    return 0;
}