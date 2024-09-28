#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    string t {}; cin >> t;

    vector<int> l {}; for (int i {0}; i < t.length(); ++i) if (t[i] == t[t.size() - 1]) l.push_back(i); l.erase(--l.end());

    for (int i {0}; i < l.size(); ++i) {
        if ((t.length() - 1 - l[i]) % 2 != 0) continue;

        pii a = {l[i] + 1, (l[i] + 1 + t.length() - 1) / 2}, b = {(l[i] + 1 + t.length() - 1) / 2 + 1, t.length() - 1};

        bool e = true;

        for (int j {a.first}, k {b.first}; j <= a.second && k <= b.second; ++j, ++k) {
            if (t[j] != t[k]) e = false;
            if (!e) break;
        }

        if (e) {cout << "YES\n"; for (int j {0}; j <= a.second; ++j) cout << t[j]; return;}
    }

    cout << "NO";
}

int main() {
    io

    solve();

    return 0;
}