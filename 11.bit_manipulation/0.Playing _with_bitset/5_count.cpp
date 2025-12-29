//counts the no. of 1s in the bitset array
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bitset<8> foo (std::string("10110011"));

    cout << foo << " has ";
    cout << foo.count() << " ones and ";// outputs no. of 1s ie 5
    cout << (foo.size()-foo.count()) << " zeros.\n";
    return 0;
}
