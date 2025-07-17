#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

void solve() {
    ll b {}, c {}, d {}; cin >> b >> c >> d;

    bitset<61> m (b), n (c), o (d);

    vector<pii> bits (61);

    for (ll i {0}; i < 61; ++i) {
        bits[i].first = 1 - n[i];
        bits[i].second = m[i];
    }

    ll a = 0;

    for (ll i {0}; i < 61; ++i) {
        if (o[i]) {
            if (bits[i].first == 1) {
                a += (1ll << i);
            } else if (bits[i].second == 1) {

            } else {
                cout << -1 << "\n"; return;
            }
        } else {
            if (bits[i].first == 0) {
                a += (1LL << i);
            } else if (bits[i].second == 0) {

            } else {
                cout << -1 << "\n"; return;
            }
        }
    }

    cout << a << "\n";
}

int main() {
    io
    tc

    return 0;
}