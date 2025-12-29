#include<bits/stdc++.h>
using namespace std;
// ??AB?C??D? how many ways are there to fill ?
//what if its circular
int n;
string st;
int dp[100100][4][4];

int rec(int i, int prev, int first){
    //pruning 
    //base case
    if(i==n){
        if(prev!=first)return 1;
        else return 0;
    }
    //cache check
    if(prev!=-1 && dp[i][prev][first]!=-1){
        return dp[i][prev][first];
    }
    //calculate
    int noWays=0;
    if(st[i]=='?'){
        for(int ch=0;ch<4;ch++){
            if(ch==prev)continue;
            if(i==0){
                noWays += rec(i+1,ch,ch);
            }else{
                noWays += rec(i+1,ch,first);
            }
        }
    }else{
        if((st[i]-'A')!=prev){
            if(i==0){
                noWays = rec(i+1,(st[i]-'A'),(st[i]-'A'));
            }else{
                noWays = rec(i+1,(st[i]-'A'),first);
            }
        }else{
            return 0;
        }
    }
    //save and return 
    if(prev!=-1) dp[i][prev][first]=noWays;
    return noWays;
}

string temp;
void generate(int i, int prev, int first){
    //base case
    if(i==n){
        return ;
    }
    //finding
    if(st[i]=='?'){
        for(int ch=0;ch<4;ch++){
            if(ch==prev)continue;
            if(i==0){
                if(rec(i+1,ch,ch)>0){
                    temp+=char(ch+'A');
                    generate(i+1,ch,ch);
                    return ;
                }
            }else{
                if(rec(i+1,ch,first)>0){
                    temp+=char(ch+'A');
                    generate(i+1,ch,first);
                    return ;
                }
            }
        }
    }else{
        if((st[i]-'A')!=prev){
            if(i==0){
                if(rec(i+1,(st[i]-'A'),(st[i]-'A'))>0){
                    temp+=st[i];
                    generate(i+1,(st[i]-'A'),(st[i]-'A'));
                    return ;
                }
            }else{
                if(rec(i+1,(st[i]-'A'),first)>0){
                    temp+=st[i];
                    generate(i+1,(st[i]-'A'),first);
                    return ;
                }
            }
        }else{
            return ;
        }
    }
}

int main(){
    cin>>n>>st;
    memset(dp,-1,sizeof(dp));
    int ans;
    if(n==1){
        if(st=="?")cout<<"4\n";
        else cout<<"0\n";
    }else{
        ans=rec(0,-1,-1);
        cout<<ans<<"\n";
    }
    if(ans>0){
        if(n==1){
            if(st=="?")cout<<"A";
            else cout<<st;
        }
        generate(0,-1,-1);
        cout<<temp;
    }
    return 0;
}