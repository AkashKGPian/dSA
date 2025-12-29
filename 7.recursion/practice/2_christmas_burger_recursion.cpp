#include <bits/stdc++.h>
using namespace std;
//atcoder
int n,x;
string str;

// string burger(int level){
//     //base case
//     if(level==0){
//         cout<<str;
//         return "P";
//     }
//     //recursive case
//     string add = burger(level-1);
//     str += "B";
//     str += add;
//     // str += "P";
//     str += add;
//     str+="B";
//     return str;
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>x;
    string st = burger(0);
    return 0;
}
