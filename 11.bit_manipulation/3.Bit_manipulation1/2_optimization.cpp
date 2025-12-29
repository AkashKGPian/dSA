#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt1[32]{};    
    for(int pos=0; pos<31; pos++){
        //for pos 0 is 2^0 
        for(int i=0;i<n;i++){//traversing all the elements of the arry lenght
            if(arr[i]&(1<<pos)){
                cnt1[pos]++;
            }
        }
    }
    return 0;
}
