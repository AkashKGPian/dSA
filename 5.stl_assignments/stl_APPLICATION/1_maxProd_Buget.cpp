#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    //prefix sum
    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }
    while(m--){
        int b;
        cin>>b;
        int idx = upper_bound(arr,arr+n,b)-arr;
        cout<<idx<<"\n";
    }
    return 0;
}
