#include <bits/stdc++.h>
using namespace std;

int fac(int n){
    if(n==0)return 1;
    return n*fac(n-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<fac(n);
    }
    return 0;
}
