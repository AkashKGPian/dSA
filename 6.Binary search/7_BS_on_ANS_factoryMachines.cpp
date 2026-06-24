#include <bits/stdc++.h>
using namespace std;
//Factory Machines -cses

#define int long long 

int n,t;//time taken by each of the mach and total no. of products to be built resp
int arr[200200];

bool check(int time){
    int total=0;
    for(int i=0;i<n;i++){
        total+= time/arr[i];
    }
    if(total>=t)return 1;
    else return 0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>t;
    for(int i=0;i<n;i++)cin>>arr[i];

    int lo=0,hi=t*(*min_element(arr,arr+n));
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
    cout<<ans<<"\n";
    return 0;
}
