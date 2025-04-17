#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    string s {}; cin >> s;

    for (int i {0}; i < s.length(); ++i) {
        if (s[i] == 'O') {
            cout << "[###OREO###]\n";
        } else if (s[i] == '&') {
			;
        } else {
			cout << "[--------]\n"; ++i;
        }
    }
}

int main() {
    io
    tc

    return 0;
}