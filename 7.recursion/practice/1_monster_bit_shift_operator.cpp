#include <bits/stdc++.h>
using namespace std;
//atcoder
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h;
    cin>>h;
    for(int i=0;i<80;i++){
        if(
            ( h >= (1LL<<i) && h < (1LL<<(i+1)) )
        ){
            cout<<(1LL<<(i+1))-1;
            break;
        }
    }
    return 0;
}
