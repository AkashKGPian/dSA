#include <bits/stdc++.h>
using namespace std;
//atcoder
#define int long long 

int monster(int h){
    if(h==1)return 1;
    int half=monster(h/2);
    return half+half+1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h;
    cin>>h;
    int health = monster(h);
    cout<<health;
    return 0;
}
