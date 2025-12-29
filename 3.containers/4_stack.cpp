#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    stack<int>s;
    s.push(5);
    cout<<s.top();
    s.pop();
    int i=0;
    while(i<4){
        s.push(6);
        cout<<"\n"<<s.top();
        i++;
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}
