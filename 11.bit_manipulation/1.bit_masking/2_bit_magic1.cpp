#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    bitset<60> x;
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        int i, j, k, l, n;
        switch (q) {
            case 1:
                cin >> i;
                if (x[i]) cout << "1\n";
                else cout << "0\n";
                break;

            case 2:
                cin >> j;
                x[j] = 1;
                break;

            case 3:
                cin >> k;
                x[k] = 0;
                break;

            case 4:
                cin >> l;
                x[l].flip();
                break;

            case 5: {
                int check = 1;
                for (int i = 0; i < 60; i++) {
                    if (x[i] == 0) check = 0;
                }
                cout << (check ? "1\n" : "0\n");
                break;
            }

            case 6: {
                int checkm = 0;
                for (int i = 0; i < 60; i++) {
                    if (x[i] == 1) checkm = 1;
                }
                cout << (checkm ? "1\n" : "0\n");
                break;
            }

            case 7: {
                int checkn = 1;
                for (int i = 0; i < 60; i++) {
                    if (x[i] == 1) checkn = 0;
                }
                cout << (checkn ? "1\n" : "0\n");
                break;
            }

            case 8: {
                int cnt = 0;
                for (int i = 0; i < 60; i++) {
                    if (x[i] == 1) cnt++;
                }
                cout << cnt << "\n";
                break;
            }

            case 9:
                cout << x.to_ullong() << "\n";
                break;
        }
    }

    return 0;
}
