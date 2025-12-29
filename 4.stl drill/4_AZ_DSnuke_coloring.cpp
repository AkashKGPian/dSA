#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second 

int dx[]={0,-1,-1,-1,0,1,1,1,0};
int dy[]={-1,-1,0,1,1,1,0,-1,0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h,w,n;
    cin>>h>>w>>n;
    
    set<pair<int,int>> black;
    set<pair<int,int>> potential_center;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        //co ordinates of black and potencial centre
        black.insert({x,y});
        for(int k=0;k<9;k++){
            potential_center.insert({x+dx[k],y+dy[k]});
        }
    }  

    vector<long long> count(10,0);

    for(auto cen : potential_center){
        if( cen.F>=2 && cen.F<=h-1 && cen.S>=2 && cen.S<=w-1 ){
            int cencnt = 0;
            for(int k=0;k<9;k++){
                if( black.find({cen.F+dx[k],cen.S+dy[k]}) != black.end() ){
                    cencnt++;
                }
            }
            count[cencnt]++;
        }
    }

    long long total_centre=(h-2LL)*(w-2LL);
    for(int i=1;i<=9;i++){
        total_centre-=count[i];
    }        

    count[0]=total_centre;
    
    for(auto v : count){
        cout<<v<<"\n";
    }
        
    return 0;
}
