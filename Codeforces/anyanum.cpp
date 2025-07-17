#include <iostream>
#include <set>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    string b {}; cin >> b;

    set<ll> n {}; for (ll i {0}; i < b.size() - 3; ++i) if (b[i] == '1' && b[i + 1] == '1' && b[i + 2] == '0' && b[i + 3] == '0') n.insert(i);

    ll q {}; cin >> q;

    while (q--) {
        ll p {}; cin >> p; char c {}; cin >> c; --p;

        if (b[p] == c) {
            if (!n.empty()) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            for (ll i {p - 3}; i <= p; ++i) n.erase(i);

            b[p] = c;

            for (ll i {p - 3}; i <= p; ++i) if (i >= 0 && i <= b.length() - 4) if (b[i] == '1' && b[i + 1] == '1' && b[i + 2] == '0' && b[i + 3] == '0') n.insert(i);

            if (!n.empty()) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    io
    tc

    return 0;
}