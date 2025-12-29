#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    
    bitset<4> x(n);//initialized x with the no. n;
    cout<<x.to_string()<<"\n";
    
    x = 5;//manually changeing the no. inside x from n to 5
    cout<<x;
    return 0;
}
