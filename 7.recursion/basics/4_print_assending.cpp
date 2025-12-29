#include <bits/stdc++.h>
using namespace std;

void print(int n){
    if(n==0)return ;
    cout<<n<<"\n";
    print(n-1);
    // cout<<" ";
    // cout<<n<<"\n";
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
        print(n);
    }
    return 0;
}
