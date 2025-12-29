#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[7]={8,5,6,9,8,4,6};
    reverse(arr,arr+7);
    for(int value : arr ){
        cout<<value<<" ";
    }
    return 0;
}
