#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bitset<4> x(0b1010);
    bitset<4> y(0b1001);
    cout<<(x|y)<<"\n";

    int n = 0b1011;
    cout<<n<<"\n-------\n";
    x=n;
    cout<<x;
    return 0;
}
