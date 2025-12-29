#include <bits/stdc++.h>
using namespace std;

void print(set<string> s){
    for(string elm : s){
        cout<<elm<<"\n";
    }
    return ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<string> s;
    s.insert("abc");//log(n)
    s.insert("cde");
    s.insert("dfs");
    s.insert("adf");
    auto it = s.find("abc");
    if(it != s.end()){
        cout<<(*it)<<"\n";
        s.erase(it);
    }

    cout<<"  ==  ==  ==  =="<<"\n";
    print(s);
    return 0;
}
