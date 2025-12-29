#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    int arr[n+1];
    long long partial_sum[n+2]{};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }    
    //making partial_Sum array
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        partial_sum[l]+=1;
        partial_sum[r+1]-=1;
    }
    //making partial sum array into prefix sum array:
    for(int i=1;i<=n;i++){
        partial_sum[i]+=partial_sum[i-1];
    }
    //sort both the array use syntax :        sort(arr+l,arr+r+1)
    sort(arr+1,arr+n+1);
    sort(partial_sum+1,partial_sum+n+1);
    long long max_sum=0;
    for(int i=1;i<=n;i++){
        max_sum+=arr[i]*partial_sum[i];
    }
    cout<<"\n"<<max_sum;
    return 0;
}
