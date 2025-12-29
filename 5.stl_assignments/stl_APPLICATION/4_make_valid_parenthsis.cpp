#include <bits/stdc++.h>
using namespace std;

//how many '(' or ')' to be added

stack<char> s;
int nsum;
    
void check(string st){
    for(int i=0;i<st.size();i++){
        char ch = st[i];
        if(ch=='('){
            s.push(ch);
        }else if(ch==')'){
            if(!s.empty()){
                s.pop();
            }else{
                nsum++;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string st;
        cin>>st;
        nsum=0;
        check(st);
        cout<<(nsum+s.size())<<"\n";
        while(!s.empty()){
            s.pop();
        }
    }
    return 0;
}
