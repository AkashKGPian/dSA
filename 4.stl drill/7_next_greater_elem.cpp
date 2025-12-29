#include <bits/stdc++.h>
using namespace std;

//4 5 2 25 7 8

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    stack<int>s;
    unordered_map<int,int>m;
    
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[i]>s.top()){
            int top = s.top();
            s.pop();
            m[top]=arr[i];
        }
        s.push(arr[i]);
    }

     while(!s.empty()) {
        m[s.top()] = -1;
        s.pop();
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "<<m[arr[i]]<<"\n";
    }
    return 0;
}
