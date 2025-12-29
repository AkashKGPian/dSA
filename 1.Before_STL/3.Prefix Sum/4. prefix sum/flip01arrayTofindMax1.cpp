#include <bits/stdc++.h>
using namespace std;
int const min_val=-5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int arr[n+1]{};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(arr[i]==1){
            count++;
        }
    }
    for(int i=1;i<=n;i++){
        if(arr[i]==1)arr[i]=-1;
        else arr[i]=1;
    }
    //making partial sum array
    for(int i=1;i<=n;i++){
        arr[i]+=arr[i-1];
    }
    //wrong way to find max since r>l-1
    // int max_el=*max_element(arr,arr+n);
    // int min_el=*min_element(arr,arr+n);
    int max_elem=min_val;
    int max_idx;
    for(int i=1;i<=n;i++){
        if(arr[i]>max_elem){
            max_elem=arr[i];
            max_idx=i;
        }
    }
    int min_elem;
    for(int i=1;i<max_idx;i++){
        min_elem=min(arr[i],min_elem);
    }

    //length of max sum subarray
    //arr[r]-arr[l-1] where arr[r]is should be max and arr[l-1] should be minimum to get the max value of expression
    int max_sum_subarray = (max_elem-min_elem);
    cout<<max_sum_subarray+count;
    return 0;
}
