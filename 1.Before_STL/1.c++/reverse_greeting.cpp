#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    cin.ignore(); // Clear the newline character from the input buffer

    string arr[n];
    for(int i=0;i<n;i++){
        getline(cin,arr[i]);
    }

    for(int i=n-1;i>=0;i--){
        cout<<"Hii "<<arr[i]<<" !";
        cout<<"\n";
    }

    return 0;
}
