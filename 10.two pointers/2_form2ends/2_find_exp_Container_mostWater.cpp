#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // sort(arr,arr+n);
    int max_val=0;
        int i=0;
        int k=n-1;
        while(i<k){
            int exp = min(arr[i],arr[k])*(abs(i-k));
            max_val=max(max_val,exp);
            if(arr[i]<=arr[k]){
                i++;
            }else{
                k--;
            }
        }    
    return 0;
}
