#include <bits/stdc++.h>
using namespace std;

int a,b,x;

int count(int n){
    int cnt=0;
    while(n!=0){
        cnt++;
        n/=10;
    }
    return cnt;
}

int check(int mid){
    int yen = a*mid+b*count(mid);
    return yen<=x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>x;

    int lo=0,hi=(1e9);
    int ans=0;

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid)==1){
            ans=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
