#include <bits/stdc++.h>
using namespace std;

int n,k;
//solution ds
int freq[1000100]{};
int dcnt=0;//distinct count 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int head=-1,tail=0;

    int ans=0;
    while(tail<n){
        while(head+1<n && ((freq[arr[head+1]]==0 && dcnt<k) ||
                                 (freq[arr[head+1]]>0 && dcnt<=k))){
            head++;
            //maintain ds
            if(freq[arr[head]]==0)dcnt++;
            freq[arr[head]]++;
        }
        //process ans and ds
        ans += (head-tail+1);//just removed max
        //tail++
        if(tail<=head){
            freq[arr[tail]]--;
            if(freq[arr[tail]]==0)dcnt--;
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
