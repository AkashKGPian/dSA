#include <bits/stdc++.h>
using namespace std;

int n;
//solution ds
int freq[1000100]{};
//all global var are declared to 0 from very begin so above{} is not needed as such
int dcnt=0;//distinct count 
vector<int>arr;

int solve(int k){
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
        if(dcnt==k){
            ans += (head-tail+1);//just removed max
        }
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
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin>>n>>k;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<(solve(k)-solve(k-1));
    return 0;
}
