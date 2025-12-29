#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bitset<4> x("1010");
    bitset<4> y("1000");

    cout<<((~x)|y)<<"\n";
    cout<<((~x)|y).flip();

    return 0;
}
