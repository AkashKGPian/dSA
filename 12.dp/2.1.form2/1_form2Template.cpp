#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
//given k partitions find the output such : max(sumation(min elem of a range aks a subseq of an array))
int n,k;
int arr[1001];

int dp[1001][1001];

int rec(int i, int x){
    //pruning
    if(i>=0 && x==0)return -INF;
    //base case
    if(i==-1){
        if(x==0)return 0;
        else return -INF;
    }
    //cache check
    if(dp[i][x]!=-1){
        return dp[i][x];
    }
    //compute
    int ans=-INF;
    int minval=INF;
    for(int j=i;j>0;j--){
        minval = min(minval,arr[j]);
        ans = max(ans, minval+rec(j-1,x-1) );
    }
    //save and return 
    return dp[i][x]=ans;
}

int main(){
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<rec(n-1,k);
    return 0;
}