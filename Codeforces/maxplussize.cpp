#include <iostream>
#include <vector>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

void solve() {
    ll n {}; cin >> n;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i];

    pii p {}, q {};

    for (ll i {0}; i < n; i += 2) {
        ++p.first;
        p.second = max(a[i], p.second);
    }

    for (ll i {1}; i < n; i += 2) {
        ++q.first;
        q.second = max(a[i], q.second);
    }

    cout << max(p.first + p.second, q.first + q.second) << "\n";
}

int main() {
    io
    tc

    return 0;
}