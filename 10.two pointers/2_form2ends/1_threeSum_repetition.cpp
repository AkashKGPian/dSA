#include <bits/stdc++.h>
using namespace std;

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
            if(arr[i]+arr[j]+arr[k]==target){// 3 3 4 5 5 7 7 7 
                int itemp=i;
                int ktemp=k;
                while(itemp<j && arr[itemp]==arr[i]){
                    itemp++;
                }
                while(ktemp>j && arr[ktemp]==arr[k]){
                    ktemp--;
                }
                cnt+=(itemp-i)*(k-ktemp);
                i=itemp;
                k=ktemp;
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
