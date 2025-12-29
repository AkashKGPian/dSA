#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n,m;
    int count=0;
    for(int a=0;a<=sqrt(1000);a++){
        for(int b=0;b<=sqrt(1000);b++){
            if(a*a+b==n && a+b*b==m){
                cout<<a<<" "<<b<<"\n";
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}
