#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ITS IMP TO NOTE THAT BOTH THE BITSETS SHOULD BE OF EQUAL SIZE ELSE YOU CANT PERFORM OPERATORS
    bitset<5> x("10101");
    bitset<5> y("1001");
    cout<<x<<" "<<y<<" \n"<<(x&y);
    return 0;
}
