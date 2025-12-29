#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    unordered_map<int,long long>m;
    long long total_sum=0;
    for(int i=0;i<n;i++){
        int r;
        cin>>r;
        m[r]+=1;
        total_sum+=r;
    }
    //else to find total sum
    // for(auto pr : m){
    //     total_sum+=pr.first*pr.second;
    // }

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int b,c;
        cin>>b>>c;

        long long count = 0;
        if(b!=c && (m.find(b)!=m.end())){
            count=m[b];
            m[c]+=count;
            total_sum-=b*count;
            total_sum+=c*count;
            m.erase(b);
        }
        cout<<total_sum<<"\n";
    }
    return 0;
}
