#include <bits/stdc++.h>
using namespace std;
//C - to 3 - atcoder
string s;
//solution data struc
int cur_num=0;
int num_del=0;
int min_possible=100;

void rec(int level){
    //base cond
    if(level==s.length()){
        if(cur_num!=0 && cur_num%3==0){//we cant del all no. to make it divisible 
            min_possible=min(min_possible,cur_num);
        }
    }
    //recusive part
    //take
    {
        int temp = cur_num;
        cur_num = cur_num*10+(s[level]-'0');
        rec(level+1);
        cur_num = temp;
    }
    //not take
    {
        num_del++;
        rec(level+1);
        num_del--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    rec(0);
    return 0;
}
