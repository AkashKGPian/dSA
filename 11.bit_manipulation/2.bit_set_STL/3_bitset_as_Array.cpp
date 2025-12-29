#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    //whats the limit of n for bitset4?
    //the no. (2^n-1) has n 1s therfore input val of n shouldn't exceed 4 cuz here its bitset4
    for(int mask=0;mask<(1<<n);mask++){
        bitset<4> x(mask);
    }
    return 0;
}
