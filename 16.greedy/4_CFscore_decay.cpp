#include <bits/stdc++.h>
using namespace std;
#define int long long

struct prob{
    int s,d,t;
};

prob problem[10010];

bool cmp(prob a, prob b){
    return 1LL*a.d*b.t > 1LL*b.d*a.t;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>problem[i].s>>problem[i].d>>problem[i].t;
    }
    sort(problem,problem+n,cmp);//gives order in which questions should be solved
    
    //finding final best optimized score achievable
    int optimalScore=0;
    int timetaken=0;
    for(int i=0;i<n;i++){
        timetaken+=problem[i].t;
        optimalScore+=problem[i].s-problem[i].d*timetaken;
    }
    cout<<optimalScore<<"\n";
    return 0;
}
