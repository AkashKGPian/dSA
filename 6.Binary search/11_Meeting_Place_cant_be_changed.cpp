#include <bits/stdc++.h>
using namespace std;
//The meeting point cant be changed - cf

using ld = long double;
int n;
int x[100100],v[100100];
const ld INF = 1e9;

bool check(ld mid){
    ld l = -INF, r = INF;
    for(int i=0;i<n;i++){
        l=max(l,x[i]-v[i]*mid);
        r=min(r,x[i]+v[i]*mid);
    }
    if(l<=r)return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>x[i];
    for(int i=0;i<n;i++)cin>>v[i];

    ld lo=0;
    ld hi=1e9;
    //why using for 
    //cuz just 80 iterations are enough 
    //mid ese bhi ans store kar hi raha hai aur 80 bhut hote hai 2^80 can make anything 0
    ld ans=0;
    for(int i=0;i<80;i++){
        ld mid = lo+(hi-lo)/2;
        if(check(mid)==1){
            ans=mid;
            hi=mid;//and not mid-1 cuz there could be floating point after mid-1 right
        }else{
            lo=mid;
        }
    }
    cout<<fixed<<setprecision(12)<<ans;
    
    return 0;
}
