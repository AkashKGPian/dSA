#include<bits/stdc++.h>
using namespace std;

//multiplication table - cf

#define int long long 

int n,m,k;

int check(int mid){
    //check if (# of elem <= val) >= k
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=min(mid/i,m);
    }
    if(cnt>=k)return 1;
    else return 0;
}

signed main(){
    cin>>n>>m>>k;
    
    int lo=1,hi=n*m;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans;
    return 0;
}