#include<bits/stdc++.h>
using namespace std;

#define int long long
// const int N = 1e6;

void solve(){
    int n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i] ;

    int m;
    cout<< "Enter m :" << "\n" ;
    cin >> m;
    int freq[m+1]{};

    //freq array building
    for(int i=0; i<n; i++){//traversing in the main array
        if( arr[i]>=0 && arr[i]<=m){
            freq[arr[i]]++;
        }
    }

    for(int i=0;i<=m;i++){
        cout << i << " : " << freq[i] << "\n" ;
    }
    return;
}

int main(){
    cout<<min(-3,-7)
    return 0;
}