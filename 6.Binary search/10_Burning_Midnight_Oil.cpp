#include <bits/stdc++.h>
using namespace std;
//Burning Midnight Oil - cf
int n,k;

bool check(int v) {
    long long total = 0;
    long long current = v;
    while (current > 0) {
        total += current;
        current /= k;
        if (total >= n) return true; // early exit
    }
    return total >= n;
}

//or

// bool check(int v) {
//     long long total=0;
//     while(v!=0){
//         total+=v;
//         v/=k;
//         if(total>=n)return 1;
//     }
//     if(total>=n)return 1;
//     return 0;
// }



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;

    int lo=0,hi=1e9;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid)==1){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
