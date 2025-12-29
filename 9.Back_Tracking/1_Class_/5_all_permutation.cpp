#include <bits/stdc++.h>
using namespace std;

int n;
int cur;
int arr[1000100];
int sol[1000100];

void gen(int i){
    if(i==n){
        cout<<i<<" : ";
        for(int i=0;i<n;i++){
            if(sol[i]!=0){
                cout<<sol[i]<<" ";
            }else{
                cout<<" ";
            }
        }
        cout<<"\n";

        return ;
    }

    gen(i+1);
    sol[cur]=arr[n-i-1];
    cur++;
    gen(i+1);
    cur--;
    sol[cur]=0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    gen(0);    
    return 0;
}
