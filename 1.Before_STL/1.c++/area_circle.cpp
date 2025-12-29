#include <bits/stdc++.h>
using namespace std;

long double pi = acos(-1);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int r;
    cin>>r;
    cout<<fixed<<setprecision(9)<<pi*r*r;
    
    return 0;
}
