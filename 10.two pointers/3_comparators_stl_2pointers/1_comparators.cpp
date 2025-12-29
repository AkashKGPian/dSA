#include <bits/stdc++.h>
using namespace std;

//sort vector of pair using comp

// 3 
// 1 6
// 5 4
// 2 3
bool comp(const pair<int,int> &a, const pair<int,int> &b){//const here means values of a and b aint gonna change in the whole func
    //c1- condition should hold true of a before b - this is how the function is made internally
    return a.first+a.second > b.first+b.second;//there cant be an equals to sym in the eqn here cuz it will do infinite swaps and -tle/runtime error
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> cards(n);
    for(int i=0;i<n;i++){
        cin>>cards[i].first>>cards[i].second;
    }
    sort(cards.begin(),cards.end(),comp);
    for(auto v : cards){
        cout<<v.first<<" "<<v.second<<"\n";
    }
    return 0;
}
