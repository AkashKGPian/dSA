#include <bits/stdc++.h>
using namespace std;

void solve(){
    double n;
    cin>>n;

    if(n != int(n)){
        cout<<floor(n)+1;
    }else{
        cout<<int(n);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
