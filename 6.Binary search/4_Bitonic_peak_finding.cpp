#include <bits/stdc++.h>
using namespace std;
// find k no. - of time an orginally sorted array has been rotated

int n;
int arr[100100];
bool check(int mid){
    if(mid==n-1)return true;
    if(arr[mid]>arr[mid+1])return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int lo=0,hi=n-1;
    int ans=-1;//here it doesnt matter what you write here cuz mid=n-1 return true

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
