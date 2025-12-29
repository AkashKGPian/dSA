#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[5] = {4,5,4,6,8};
    //max_element returns ptr
    //max_element[)
    int* ptr = max_element(arr,arr+5);
    cout<<*(ptr);
    return 0;
}
