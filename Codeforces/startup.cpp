#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

void solve() {
    ll n {}, k {}; cin >> n >> k;

    map<ll, ll> m {}; for (ll i {0}; i < k; ++i) {
        ll b {}, c {}; cin >> b >> c;
        m[b] += c;
    }

    vector<ll> c {}; for (const auto& i : m) c.push_back(i.second); sort(c.begin(), c.end(), greater<ll>());

    ll t {0}; for (ll i {0}; i < min(n, static_cast<ll>(m.size())); ++i) t += c[i];

    cout << t << "\n";
}

int main() {
    io
    tc

    return 0;
}