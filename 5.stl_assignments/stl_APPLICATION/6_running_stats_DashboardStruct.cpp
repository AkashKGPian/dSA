#include <bits/stdc++.h>
using namespace std;

struct data_dashboard{
    int cnt=0;
    int sum=0;
    int sqsum=0;

    //mode
    map<int,int> freq;
    multiset<pair<int,int>> freq_order;
    //median
    multiset<int> low,high;

    void balance(){
        if(low.size()<high.size()){//you could use while here but then ~ come here
            int temp = *high.begin();
            high.erase(high.find(temp));
            low.insert(temp);
        }else if( (low.size()-high.size()) > 1 ){//you could use while here but then ~ come here
            int temp = *low.rbegin();
            low.erase(low.find(temp));
            high.insert(temp);
        }
    }


    void insert(int x){
        cnt++;
        sum+=x;
        sqsum+=x*x;

        // mode 
        if( freq_order.find(make_pair(freq[x],x)) != freq_order.end() ){
            freq_order.erase(freq_order.find(make_pair(freq[x],x)));
        }
        freq[x]++;
        freq_order.insert({freq[x],x});
        
        //median
        if(low.empty())low.insert(x);
        if(x <= *low.rbegin()){
            low.insert(x);
        }else{
            high.insert(x);
        }
        balance();
    }
    void remove(int x){
        cnt--;
        sum-=x;
        sqsum-=x*x;

        // mode 
        if( freq_order.find(make_pair(freq[x],x)) != freq_order.end() ){
            freq_order.erase(freq_order.find(make_pair(freq[x],x)));
        }
        freq[x]--;
        if(freq[x])freq_order.insert({freq[x],x});//even if you dont have the check it works cuz 0 enter nahi hoga also neg to enter ho hi nahi sakta bcz of the 1st cond
        
        //median
        if(low.find(x)!=low.end()){
            low.erase(low.find(x));
        }else if(high.find(x)!=high.end()){
            high.erase(high.find(x));
        }
        balance();
    }
    double mean(){
        return (double)sum/cnt;
    }
    double variance(){
        return ( (double)sqsum/cnt - (mean()*mean()) );
    }
    int mode(){
        return freq_order.rbegin()->second;
    }
    double median(){
        //~ balance()
        if( (low.size()+high.size()) % 2 ){
            return *low.rbegin();
        }else{
            return (*low.rbegin() + *high.begin())/2.0;
        }
    }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    data_dashboard db;
    db.insert(1);
    db.insert(2);
    db.insert(4);
    // cout << fixed << setprecision(6);
    cout << db.mean() << "\n";
    cout << db.median() << "\n";
    cout << db.variance() << "\n";
    cout << db.mode() << "\n"; 
    return 0;
}
