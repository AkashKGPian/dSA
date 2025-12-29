#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //& at lhs makes a new variable pointing at x
    int x=5;
    int &y = x;
    cout<<y<<"\n";
    x++;
    cout<<y;
    cout<<"  "<<x;
    return 0;
}
