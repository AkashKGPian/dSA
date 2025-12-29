#include <bits/stdc++.h>
using namespace std;
//point on line - cf
//optimizing problem keh sakta hai

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,d;
    cin>>n>>d;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    long long ans = 0;
    for(int i=0;i<n;i++){
        int lim = arr[i]+d;
        int extras = (upper_bound(arr+i+1,arr+n,lim)-(arr+i+1));
        ans+= 1LL*extras*(extras-1)/2;
    }
    cout<<ans<<"\n";
    return 0;
}
