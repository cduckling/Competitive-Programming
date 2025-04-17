#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

ll distance(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void solve() {
    ll n {}; cin >> n;

    vector<pii> circles (n); for (ll i {0}; i < n; ++i) cin >> circles[i].first >> circles[i].second;

    pii s {}, t {}; cin >> s.first >> s.second >> t.first >> t.second;

    for (auto i : circles) {
        if (distance(i, t) <= distance(s, t)) {cout << "NO\n"; return;}
    }

    cout << "YES\n";
}

int main() {
    io
    tc

    return 0;
}