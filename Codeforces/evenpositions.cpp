#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    string s {}; cin >> s;

    for (int i {0}; i < n; ++i) {
        if (i % 2 != 0) continue;

        bool p = s[i - 1] == ')';

        if (s[i] == '_') {
            if (i == 0) {
                s[i] = '(';
            } else if (p) {
                s[i] = '(';
            } else {
                s[i] = ')';
            }
        }
    }

    vector<int> l {}, r {}; for (int i {0}; i < n; ++i) {
        if (s[i] == '(') {
            l.push_back(i);
        } else {
            r.push_back(i);
        }
    }

    int cost {0}; for (int i {0}; i < n / 2; ++i) {cost += r[i] - l[i];} cout << cost << "\n";
}

int main() {
    io
    tc

    return 0;
}