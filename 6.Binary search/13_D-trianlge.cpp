#include <bits/stdc++.h>
using namespace std;
//dtriangles - at
// #define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++)cin>>l[i];
    sort(l,l+n);
    
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1; j<n ; j++){
            int cnt = lower_bound(l+j+1,l+n,(l[i]+l[j]))-(l+j+1);
            ans+=cnt;
        }
    }
    cout<<ans<<"\n";
    return 0;
}









