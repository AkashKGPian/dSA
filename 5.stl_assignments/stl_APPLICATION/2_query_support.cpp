#include<bits/stdc++.h>
using namespace std;

#define int long long

struct bag{
    map<int,int> m;
    int sum_tol=0;

    void add(int x){
        m[x]++;
        sum_tol+=x;
    }
    void remove(int x){
        auto it = m.find(x);
        if(it != m.end()){
            sum_tol -= x;
            if(it->second == 1){
                m.erase(it);
            } else {
                it->second--;
            }
        }
    }
    int get_sum(){
        if(!m.empty()){
            return sum_tol;
        }else{
            return 0;
        }
    }
    int get_min(){
        if(!m.empty()){
            return m.begin() -> first;
        }else{
            return -1;
        }
    }
    int get_max(){
        if(!m.empty()){
            return m.rbegin() -> first;
        }else{
            return -1;
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bag bg;
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        if(x==1){
            int y;
            cin>>y;
            bg.add(y);
        }else if(x==2){
            int y;
            cin>>y;
            bg.remove(y);
        }else if(x==3){
            char ch;
            cin>>ch;
            if(ch=='?') cout<<bg.get_min()<<"\n";
        }else if(x==4){
            char ch;
            cin>>ch;
            if(ch=='?') cout<<bg.get_max()<<"\n";
        }else if(x==5){
            char ch;
            cin>>ch;
            if(ch=='?') cout<<bg.get_sum()<<"\n";
        }
    }
    
    return 0;
}