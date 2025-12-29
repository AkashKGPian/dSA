#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int lo = 0, hi = n-1;
    int ans = -1;
    while(lo<=hi){//means there are elements in the search space
        int mid = (lo+hi)/2; // lo + (hi-lo)/2
        if(arr[mid]==1){
            ans=mid;
            hi=mid-1;
        }else if(arr[mid]==0){
            lo=mid+1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
