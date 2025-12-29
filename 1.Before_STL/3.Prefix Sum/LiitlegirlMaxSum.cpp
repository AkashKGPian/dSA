#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    //prefix sum
    long long partial[n+2]{};
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        partial[l]+=1;
        partial[r+1]-=1;
    }
    //partial sum or prefix sum
    for(int i=1;i<=n;i++){
        partial[i]+=partial[i-1];
    }
    //sorting prefix sum
    sort(partial+1,partial+n+1);

    //sorting the org array
    sort(arr+1,arr+n+1);

    long long ans = 0;
    for(int i=1;i<=n;i++){
        ans += arr[i]*partial[i];
    }
    cout<<ans;
    return 0;
}
