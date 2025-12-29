#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[4]={1,2,3,4};
    int value=0;
    //the problem with while loop is it doesnt prints the org array
    //hence for getting all perm
    while(next_permutation(arr,arr+4)){
        for(int elem : arr){
            cout<<elem<<" ";
        }
        value++;
        cout<<"\n";
    }
    cout<<value<<"\n";
    return 0;
}
