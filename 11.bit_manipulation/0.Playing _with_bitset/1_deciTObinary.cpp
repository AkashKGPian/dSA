#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    bitset<4>x;
    //max no. that can be input is 2^4-1 = 15
    x = n;

    cout<<x.to_string()<<"\n";

    //printing no.s uptill 2^n-1 from 0 in binary rep
    // for(int mask=0; mask<(1<<n); mask++){
    //     x = mask;
    //     cout<<x.to_string()<<"\n";
    // }
    return 0;
}
