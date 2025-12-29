#include <bits/stdc++.h>
using namespace std;

//bitonic means STRICTLY inc and then dec
int arr[100100];

bool check(int i, int n){
    if(i==n-1)return 1;
    if(arr[i]>arr[i+1])return 1;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        //finding peak 
        //peak is the index of highest elem
        int lo=0,hi=n-1;
        int peak=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,n)){
                hi=mid-1;
                peak=mid;
            }else{
                lo=mid+1;
            }
        }

        while(q--){
            int k;
            cin>>k;

            lo=0,hi=peak;
            vector<int>final;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(arr[mid]==k){
                    final.push_back(mid+1);
                    break;
                }else if(arr[mid]>k){
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }

            lo=peak+1,hi=n-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(arr[mid]==k){
                    final.push_back(mid+1);
                    break;
                }else if(arr[mid]>k){
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }
            for(auto elm : final){
                cout<<elm<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
