#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<bool> vb;
typedef multiset<ll> msi;
typedef set<ll> si;
typedef map<ll, ll> mi;
typedef map<ll, vector<ll>> mvi;
typedef map<ll, pair<ll, ll>> mpii;
typedef map<ll, bool> mb;

void solve() {
    ll n; cin >> n;

    vi c (n + 1); for (ll i = 1; i <= n; i++) cin >> c[i];

    ll k; cin >> k;

    vpii ops; ll cost = inf; for (ll i = n; i >= 1; i--) if (c[i] < cost) {
        ops.emplace_back(c[i], i);
        cost = c[i];
    }

    reverse(ops.begin(), ops.end());

    vi h (n + 1); for (ll i = 1; i <= ops[0].second; i++) h[i] = k / ops[0].first; k -= k / ops[0].first * ops[0].first;

    for (ll i = 1; i < ops.size(); i++) {
        pii r = {0, h[ops[i - 1].second]};

        while (r.first != r.second) {
            const ll mid = (r.first + r.second + 1) / 2;

            ll K = k; K += mid * ops[i - 1].first; K -= mid * ops[i].first;

            if (K >= 0) {
                r.first = mid;
            } else {
                r.second = mid - 1;
            }
        }

        k += r.first * ops[i - 1].first; k -= r.first * ops[i].first;

        for (ll j = ops[i - 1].second + 1; j <= ops[i].second; j++) h[j] = r.first;
    }

    for (ll i = 1; i <= n; i++) cout << h[i] << " "; cout << "\n";
}

int main() {
    io
    tc

    return 0;
}