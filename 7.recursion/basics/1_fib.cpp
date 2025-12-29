#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n<=1)return n;
    return fib(n-1)+fib(n-2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<fib(n)<<" ";
    }
    
    return 0;
}
