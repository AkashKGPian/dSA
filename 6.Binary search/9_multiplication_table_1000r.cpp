#include<bits/stdc++.h>
using namespace std;

//multiplication table - cf
//count no. of time x appeared in the array

#define int long long 

int n,x;

signed main(){
    cin>>n>>x;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(x%i==0 && x/i<=n) cnt++;
    }
    cout<<cnt;
    return 0;
}