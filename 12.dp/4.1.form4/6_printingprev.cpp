#include <bits/stdc++.h>
using namespace std;

int n;
int x[101],y[101];
int dp[101][101];
int back[101][101];
int opb[101];//opening bracket
int clb[101];//closing bracket

int rec(int l, int r){
    //base case
    if(l>r)return 0;
    if(l==r) return 0;
    //cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    //transitions
    int ans=1e9;
    for(int mid=l;mid<r;mid++){
        if( (rec(l,mid)+rec(mid+1,r)+
                    x[l]+y[mid]+y[r] ) < ans ){
            ans=rec(l,mid)+rec(mid+1,r)+x[l]+y[mid]+y[r];
            back[l][r]=mid;
        }
    }
    //save and return 
    return dp[l][r]=ans;
}

void generate(int l, int r){
    if(l==r)return ;
    // cout<<"merge ("<<l<<", "<<mid - you dont have mid you have to save mid n back tracing array
    opb[l]++;
    clb[r]++;
    int mid=back[l][r];
    generate(l,mid);
    generate(mid+1,r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,n);
    generate(1,n);
    for(int i=1;i<=n;i++){
        for(int x=0;x<opb[i];x++){
            cout<<" (";
        }
        cout<<" "<<i<<" ";
        for(int x=0;x<clb[i];x++){
            cout<<") ";
        }
    }
    return 0;
}
