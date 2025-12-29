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
        while({exists} && {can we eat}){
            head++;
            //maintain ds
        }
        //process ans and ds
        //tail++
        if(tail<=head){
            if(arr[tail]==0)cnt0--;
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    return 0;
}
