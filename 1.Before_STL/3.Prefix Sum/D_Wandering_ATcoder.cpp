#include <bits/stdc++.h>
using namespace std;


#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int arr[n+1]{};

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int max_partial_sum=0;
    //first partial sum
    for(int i=1;i<=n;i++){
        arr[i]+=arr[i-1];
        max_partial_sum=max(max_partial_sum,arr[i]);
    }
    int max_elem=0;
    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
        max_elem=max(max_elem,arr[i]);
    }
    //max elemnt in the process would be prefix sum 2nd time + the max_partial sum when we were finding the prefix sum for the first time 
    cout<<max(max_elem,max_elem+max_partial_sum);
    return 0;
}
