#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int head=-1,tail=0;
    
    int cnt0=0;
    int ans=0;
    while(tail<n){
        while(head<(n-1) && ((arr[head+1]==0 && cnt0<k) || (arr[head+1]==1 && cnt0<=k))){
            head++;
            //maintain ds
            if(arr[head]==0)cnt0++;
        }
        //process ans and ds
        ans = max(ans,head-tail+1);
        //tail++
        if(tail<=head){
            if(arr[tail]==0)cnt0--;
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
