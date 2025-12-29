#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,l;
    cin>>n>>l;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // [1,1,2,6,7,8,9,11]
    sort(arr,arr+n);

    int lo=0,hi=n-1;
    int ans=-1;
    while(lo<=hi){//<= is important
        int mid=lo+(hi-lo)/2;
        if(arr[mid]>=l){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
