#include<bits/stdc++.h>
using namespace std;

int n;
int arr[10010];
int prefix[10010];
int dp[1010][1010];

int suminRange(int l, int r){
    return prefix[r]-((l==0)? 0 : prefix[l-1]);
}

int rec(int l, int r){
    //base case
    if(l==r)return 0;
    //cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    //transitions
    int ans=-1e9;
    for(int p=l;p<r;p++){//partition=p
        ans=max(ans,(suminRange(l,p)%100)*(suminRange(p+1,r)%100)+
                        rec(l,p)+rec(p+1,r));
    }
    //save and return 
    return dp[l][r]=ans;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i==0)prefix[i]=arr[i];
        else prefix[i]=prefix[i-1]+arr[i];
    }
    return 0;
}