/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> v;
    // for(int i=0;i<5;i++){
    //     int temp;
    //     cin>>temp;
    //     v.push_back(temp);
    // }
    int n;
    cin>>n;
    vector<int> p(n);
    //p.resize(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cout<<p[i];
    }
    
    return 0;
}