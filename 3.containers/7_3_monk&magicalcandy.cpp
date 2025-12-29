#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,k;
    cin>>t>>n>>k;
    while(t--){
        multiset<long long> ms;
        long long count=0;
        while(n--){
            long long r;
            cin>>r;
            ms.insert(r);
        }
        while(k--){
            auto it = --(ms.end());
            int max_val= *it;
            count+=max_val;
            ms.erase(max_val);//here /it/ should come
            ms.insert(max_val/2);
        }
        cout<<count<<"\n";
    }
    return 0;
}
