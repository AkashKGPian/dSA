#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
// MIXTURES - Mixtures spoj

int n;
int arr[101];
int dp[101][101];
int prefixSum[101];

int getSum(int l, int r){
    return prefixSum[r]-((l==0)? 0 : prefixSum[l-1]);
}

int rec(int l, int r){//returns the min smoke 
    //pruning
    //base case
    if(l==r){
        return 0;
    }
    //cache check
    if(dp[l][r]!=-1)return dp[l][r];
    //compute
    int ans=INF;
    for(int mid=l;mid<r;mid++){
        ans = min( ans, rec(l,mid)+rec(mid+1,r)+
                        +(getSum(l,mid)%100)*(getSum(mid+1,r)%100)
                );
    }
    //save and return 
    return dp[l][r]=ans;
}

int main(){
    while(cin>>n){
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i==0)prefixSum[i]=arr[i];
            else prefixSum[i]=prefixSum[i-1]+arr[i];
        }
        cout<<rec(0,n-1)<<"\n";
    }
    return 0;
}