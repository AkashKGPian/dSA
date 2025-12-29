#include <bits/stdc++.h>
using namespace std;

//current state
int n,d;
string curstr;
int depth;

//LCCM brute force
void rec(int level) { //  WHICH LEVEL?
	//level = index
	cout<<"DEB : Level "<< level<<" "<<curstr<<"\n";
	if(level==n) {
		if(depth==0) {
			cout<<curstr<<"\n";
		}
		return ;
	}


	//standard backtracking problem;
	//'('
	{
		if(depth+1<=d) {
			curstr+='(';
			depth++;
			rec(level+1);
			depth--;
			curstr.pop_back();
		}
	}
	//')'
	{
		if(depth - 1 >= 0) {
			curstr+=')';
			depth--;
			rec(level+1);
			depth++;
			curstr.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>d;
	rec(0);
    return 0;
}
