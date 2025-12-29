#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s ;
    //changing a string to integer (no.)
    int value = stoi(s);
    cout<<value+7<<endl;

    string str = to_string(value);
    cout<<str;

    //changing a string to integer (no.)
    long long val = stoll(str);
    return 0;
}