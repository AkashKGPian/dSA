/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cout<<v[i];
    }
    cout<<"\n";
    int target;
    cin>>target;
    
    sort(v.begin(),v.end());
    auto iter = lower_bound(v.begin(),v.end(),target);
    cout<<*iter<<"\n";
    iter++;
    cout<<*iter<<"\n";
    cout<<"Index of the element on which iter is pointing\nOr say the no. of elemtents less than the lower bound"<<" "<<iter-v.begin()<<"\n";
    return 0;
}