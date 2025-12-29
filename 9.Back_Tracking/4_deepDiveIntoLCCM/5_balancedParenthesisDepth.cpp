#include <bits/stdc++.h>
using namespace std;

int n, k;
string str = "";
int depth;
int max_depth = 0;

void recfill(int level) {
    if (level == n) {
        if (depth == 0 && max_depth == k) {
            cout << str << "\n";
        }
        return;
    }
    // (
    {
        if (depth < k) {
            str += "(";
            depth++;
            int old_max = max_depth;
            max_depth = max(max_depth, depth);
            recfill(level + 1);
            str.pop_back();
            depth--;
            max_depth = old_max;
        }
    }
    // )
    {
        if (depth - 1 >= 0) {
            str += ")";
            depth--;
            recfill(level + 1);
            str.pop_back();
            depth++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    recfill(0);
    return 0;
}
