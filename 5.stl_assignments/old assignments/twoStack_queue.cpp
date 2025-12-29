#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &s1, stack<int> &s2, bool &flag){
    string st;
    cin>>st;
    if(flag){
        if(st=="push"){
        int x;
        cin>>x;
        s1.push(x);
        }
        if(st=="pop"){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            flag=false;
            if(!s2.empty()){
                cout<<s2.top()<<"\n";
                s2.pop();
            }
        }
        if(st=="front"){
            if (!s2.empty()) {
                cout << s2.top() << "\n";
            } else {
                // If s2 is empty, move from s1
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                flag = false;
                if (!s2.empty()) {
                    cout << s2.top() << "\n";
                } else {
                    cout << "Empty\n"; // Optional: handle empty case
                }
            }
        }
    }else{
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        flag=true;
        if(st=="push"){
        int x;
        cin>>x;
        s1.push(x);
        }
        if(st=="pop"){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            flag=false;
            if(!s2.empty()){
                cout<<s2.top()<<"\n";
            }
        }
        if(st=="front"){
            if (!s2.empty()) {
                cout << s2.top() << "\n";
            } else {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                flag = false;
                if (!s2.empty()) {
                    cout << s2.top() << "\n";
                } else {
                    cout << "Empty\n"; // Optional: handle empty case
                }
            }
        }
    }
    
    return ;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int q;
        cin>>q;

        stack<int> s1,s2;
        bool flag_first_scene=true;

        while(q--){
            solve(s1,s2,flag_first_scene);
        }
    }
    
    return 0;
}









#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s1, stack<int> &s2, bool &flag) {
    string st;
    cin >> st;
    if (flag) {
        if (st == "push") {
            int x;
            cin >> x;
            s1.push(x);
        }
        if (st == "pop") {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            flag = false;
            if (!s2.empty()) {
                cout << s2.top() << "\n";
                s2.pop();
            }
        }
        if (st == "front") {
            if (!s2.empty()) {
                cout << s2.top() << "\n";
            } else {
                // If s2 is empty, move from s1
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                flag = false;
                if (!s2.empty()) {
                    cout << s2.top() << "\n";
                } else {
                    cout << "Empty\n"; // Optional: handle empty case
                }
            }
        }
    } else {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        flag = true;
        if (st == "push") {
            int x;
            cin >> x;
            s1.push(x);
        }
        if (st == "pop") {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            flag = false;
            if (!s2.empty()) {
                cout << s2.top() << "\n";
            }
        }
        if (st == "front") {
            if (!s2.empty()) {
                cout << s2.top() << "\n";
            } else {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                flag = false;
                if (!s2.empty()) {
                    cout << s2.top() << "\n";
                } else {
                    cout << "Empty\n"; // Optional: handle empty case
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        int q;
        cin >> q;

        stack<int> s1, s2;
        bool flag_first_scene = true;

        while (q--) {
            solve(s1, s2, flag_first_scene);
        }
    }

    return 0;
}
