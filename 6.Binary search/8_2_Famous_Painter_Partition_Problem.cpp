#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[100100];

bool check(int mid){
    for(int i=0;i<n;i++){
        
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){

        cin>>n>>k;
        int lo=0,hi=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            lo=max(lo,arr[i]);
            hi+=arr[i];
        }
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid)==1){
                mid=ans;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
