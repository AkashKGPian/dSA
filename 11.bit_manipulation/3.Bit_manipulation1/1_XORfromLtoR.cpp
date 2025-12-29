#include <bits/stdc++.h>
using namespace std;

#define int long long

int XOR(int l){
    if(l%4==0)return l;
    if(l%4==1)return 1;
    if(l%4==2)return l+1;
    if(l%4==3)return 0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int l,r;
    cin>>l>>r;
    //l^(l+1)^(l+2)...^R
    cout<<(XOR(r)^XOR(l-1));
    return 0;
}
