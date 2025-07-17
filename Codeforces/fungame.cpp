#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

const int length = 2 * 1e5;

void solve() {
    int n {}; cin >> n;

    string s {}, t {}; cin >> s >> t;

    int c {0};

    for (int i {0}; i < n; ++i) {
        if (s[i] == '0' && t[i] == '1' && c == 0) {
           cout << "NO\n"; return;
        }

        if (s[i] == '1') {
            ++c;
        }
    }

    cout << "YES\n";
}

int main() {
    io
    tc

    return 0;
}