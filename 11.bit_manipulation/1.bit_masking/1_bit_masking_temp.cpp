#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //printing all the subsets along with mask
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int mask=0;mask<(1<<n);mask++){
        //mask-outter loop runs 2^n times. Where 2^n-1 is the last element which represent a unique sett 
        // 2^n-1 is the no. with n 1s in binary notation
        //inner loop has to run n times 
        cout<<"mask "<<mask<<" : {";
        //lets say mask is 3 -> 0 1 1
        for(int i=0;i<n;i++){
            if((mask>>i)&1)cout<<arr[i]<<", ";
        }
        cout<<"}\n";
    }
    return 0;
}
