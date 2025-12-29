#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bitset<5> x(0b10101);
    cout<<(x<<2)<<"\n"<<x<<"\n";

    bitset<4> bar ("0011");

    cout << (bar<<1) << '\n';         // 0110 (SHL)
    cout << (bar>>1) << '\n';         // 0001 (SHR)
    return 0;
}
