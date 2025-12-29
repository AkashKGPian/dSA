#include<bits/stdc++.h>
using namespace std;

void func(int i, int j, int n){
    int k=0;
    if(i+j==n-1 || i==j+1-n){
        cout<<k+1<<" ";
    }
    else cout<<"  ";
    return ;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<2*n-1;j++){
                func(i,j,n);
            }
            cout<<"\n";
        }
    }
    
    return 0;
}