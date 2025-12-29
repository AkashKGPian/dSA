#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9+7;

int modinv(int a, int mod = MOD) {
    int res = 1, b = mod - 2;
    while (b) {
        if (b & 1) res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

int fractionalModOutput(long long p, long long q) {
    int gcd = __gcd((int)p, (int)q);
    p /= gcd;
    q /= gcd;
    int invQ = modinv(q);
    return (1LL * (p % MOD) * invQ) % MOD;
}

struct dash_board{
    int cnt=0;
    int sum=0;
    
    //getMode
    map<int,int> freq;
    multiset<pair<int,int>> freq_order;//<freq[x],x>
    multiset<pair<int, int>>::reverse_iterator it;
    
    //getMedian
    multiset<int> low,high;
    
    void balance(){
        if( low.size()<high.size() ){
            int temp = *high.begin();
            high.erase(high.find(temp));
            low.insert(temp);
        }
        if( (low.size()-high.size()) > 1 ){
            int temp = *low.rbegin();
            low.erase(low.find(temp));
            high.insert(temp);
        }
    }
    
    void shift_tomin(){
        if (freq_order.empty()) return;
    
        int temp = (*freq_order.rbegin()).first;
        it = freq_order.rbegin();
    
        // Safely shift back while elements have the same max frequency
        auto temp_it = it;
        while (true) {
            auto next = temp_it;
            ++next; // move reverse iterator forward (towards rend)
            if (next == freq_order.rend() || next->first < temp) break;
            temp_it = next;
        }
        it = temp_it;
    }
    
    void insert_(int x){
        cnt++;
        sum+=x;
        
        //Mode
        if( freq_order.find({freq[x],x}) != freq_order.end() ){
            freq_order.erase(freq_order.find({freq[x],x}));
        }
        freq[x]++;
        if(freq[x])freq_order.insert({freq[x],x});
        shift_tomin();
        
        // median
        if(low.empty())low.insert(x);
        if(x <= *low.rbegin()){
            low.insert(x);
        }else{
            high.insert(x);
        }
        balance();
    }
    void remove_(int x){
        cnt--;
        sum-=x;
        
        //Mode
        if( freq_order.find({freq[x],x}) != freq_order.end() ){
            freq_order.erase(freq_order.find({freq[x],x}));
        }
        freq[x]--;
        if(freq[x])freq_order.insert({freq[x],x});
        shift_tomin();
        
        // median
        if(low.find(x)!=low.end()){
            low.erase(low.find(x));
        }else if(high.find(x)!=high.end()){
            high.erase(high.find(x));
        }
        balance();
    }
    
    int getMean(){
        return fractionalModOutput(sum, cnt);
    }
    int getMedian() {
        if (cnt == 0) return -1; // Fix: use integer consistent return value
        if ((low.size() + high.size()) % 2 == 1) {
            return *low.rbegin();
        } else {
            long long a = *low.rbegin(), b = *high.begin();
            return fractionalModOutput(a + b, 2);
        }
    }

    int getMode(){
        if(freq_order.empty()){
            return -1;
        }else{
            return (*it).second;
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int q;
        cin>>q;
        dash_board db;
        while(q--){
            string st;
            cin>>st;
            if(st=="insert"){
                int x;
                cin>>x;
                db.insert_(x);
            }else if(st=="remove"){
                int x;
                cin>>x;
                db.remove_(x);
            }else if(st=="getMean"){
                cout<<( db.getMean()%MOD )<<"\n";
            }else if(st=="getMedian"){
                cout<<( db.getMedian()%MOD )<<"\n";
            }else if(st=="getMode"){
                cout<<db.getMode()<<"\n";
            }
        }
    }
    return 0;
}