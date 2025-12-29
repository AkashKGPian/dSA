#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    bitset<8> x;
    for(int mask=0; mask<(1<<n); mask++){
        x = mask;
        //printing all the binary no. ie all the int mask( from 0 to 2^n-1 no.(s)) are converted to binary in string output
        cout<<x.to_string()<<"\n";
    }
    return 0;
}
