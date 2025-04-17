#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}, k {}; cin >> n >> k;

    map<ll, ll> freq {}; for (ll i {0}; i < n; ++i) {
        ll a {}; cin >> a; ++freq[a];
    }

    vector<pair<ll, ll>> f {}; for (auto i : freq) f.push_back(i);

    vector<ll> pref (f.size() + 1, 0); for (ll i {1}; i <= f.size(); ++i) pref[i] = pref[i - 1] + f[i - 1].second;

    ll c {0}, a {0};
    for(ll i {0}; i < f.size(); ++i) {
        while(a <= i && (f[i].first - f[a].first) > (i - a)) ++a;
        while(a <= i && (i - a + 1) > k) ++a;
        
        c = max(pref[i + 1] - pref[a], c);
    }

    cout << c << "\n";
}

int main() {
    io
    tc

    return 0;
}