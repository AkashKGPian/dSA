#include<bits/stdc++.h>
using namespace std;
#define int long long

//given its a 1 centre tree find no. of diameters

int n;
vector<vector<int>> g;
vector<int> depth;
vector<int> par;
vector<int> diaLeafCnt;
int d;
int cnt;

void dfs(int nn, int pp, int dd){
    par[nn]=pp;
    depth[nn]=dd;
    if(d>0 && d%2==0){
        if(depth[nn]==d/2-1)cnt++;
    }else if(d>0 && d%2!=0){
        if(depth[nn]==(int)d/2)cnt++;
    }
    for(auto v:g[nn]){
        if(v==pp)continue;
        dfs(v,nn,dd+1);
    }
}

signed main(){
    cin>>n;
    if(n == 1) { // Corner case fix
        cout << 1;
        return 0;
    }
    g.resize(n+1);
    par.resize(n+1);
    depth.resize(n+1);
    
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //finding one of the diametric end point
    dfs(1,-1,0);
    int maxChild=1;
    for(int j=2;j<=n;j++){
        if(depth[j]>depth[maxChild]){
            maxChild=j;
        }
    }
    dfs(maxChild,-1,0);
    maxChild=1;
    for(int j=2;j<=n;j++){
        if(depth[j]>depth[maxChild]){
            maxChild=j;
        }
    }
    //maxChild = diametric end point
    //diameter is 
    d=depth[maxChild];
    
    //you have to go to the centre now
    int temp=maxChild;//centre
    for(int i=1;i<=d/2;i++){
        temp=par[temp];
    }
    int c2 = par[temp];
    
    if(d%2==0){
        for(auto v:g[temp]){
            cnt=0;//here no need to assign depth vector =0 again as it will be overridden again while dfs
            dfs(v,temp,0);
            diaLeafCnt.push_back(cnt);
        }
        long long ans = 0;
        long long sum = 0;
        // diaLeafCnt = [2, 3, 4]
        for(auto x : diaLeafCnt){
            ans += sum * x;
            sum += x;
        }
        cout << ans;
    }else{
        long long ans=1;
        
        cnt=0;
        dfs(temp,c2,0);
        ans*=cnt;
        
        cnt=0;
        dfs(c2,temp,0);
        ans*=cnt;
        
        cout<<ans;
    }
    return 0;
}