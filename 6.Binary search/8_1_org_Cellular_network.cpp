#include <bits/stdc++.h>
using namespace std;

//cellular network -cf

#define int long long
int n,m;
int arr[200200];
int brr[200200];

int check(int mid){
    int towerPlanted = 0;
    int lastTowerCoverTill = -1e18;
    for(int i=0;i<n;i++){
        if(lastTowerCoverTill>=arr[i]){
            continue;
        }
        //else this city needs a tower
        int lo = arr[i]-mid;
        int hi = arr[i]+mid;

        auto itr = upper_bound(brr,brr+m,hi);
        if(itr==brr){
            return 0;
        }else{
            itr--;
            if(lo<=*itr){
                towerPlanted++;
                lastTowerCoverTill = (*itr)+mid;
            }else{
                return 0;
            }
        }
    }
    // if(towerPlanted>k)return 0;
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<m;i++)cin>>brr[i];

    int lo=0;
    int hi=2e9;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans;    
    return 0;
}
