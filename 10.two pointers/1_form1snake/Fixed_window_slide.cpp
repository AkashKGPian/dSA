#include<bits/stdc++.h>
using namespace std;

const int MAX_INT = 1e9;
int arr[1000100];
int m[1000100];//map -> tle


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int dnt=0;
        int ans=MAX_INT;
        int tail=0;
        int head=-1;
        while(tail<n){
            while(head+1<n && head-tail+1<d){//condn
                head++;
                if(m[arr[head]] == 0) dnt++;
                    m[arr[head]]++;
            }
            if(head-tail+1 == d) ans = min(dnt,ans);//condn

            if(tail<=head){
                m[arr[tail]]--;
                if(m[arr[tail]]==0)dnt--;
                tail++;
            }else{
                tail++;
                head=tail-1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}