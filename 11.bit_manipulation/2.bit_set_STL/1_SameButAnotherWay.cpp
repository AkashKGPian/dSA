#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    //if n=5 (32 16 8 4 2 1
    for(int mask=0;mask<(1<<n);mask++){
        bitset<8> x(mask);
        cout<<x.to_string()<<"\n";
    }
    return 0;
}
