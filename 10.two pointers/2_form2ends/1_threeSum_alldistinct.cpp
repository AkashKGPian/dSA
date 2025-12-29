#include <bits/stdc++.h>
using namespace std;
//easy

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,target;
    cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //dont forget sorting 
    //you forgot
    sort(arr,arr+n);
    
    int cnt=0;
    for(int j=0;j<n;j++){
        int i=0;
        int k=n-1;
        while(i<j && j<k){
            if(arr[i]+arr[j]+arr[k]==target){
                cnt++;
                i++;
                k--;
            }else if(arr[i]+arr[j]+arr[k]>target){
                k--;
            }else{
                i++;
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
