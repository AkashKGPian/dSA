#include <bits/stdc++.h>
using namespace std;

int _gcd(int a, int b){
    if(b == 0) return a;
    return _gcd(b,a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>a>>b;
    int ans = _gcd(a,b);
    cout<<ans;
    return 0;
}
