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

vector<ll> divs[100001]; ll cnt[100001], rep[100001];

void solve() {
    ll n; cin >> n;

    vi a (n); for (ll i = 0; i < n; i++) cin >> a[i]; sort(a.begin(), a.end());

    for (ll i = 1; i <= a[n - 1]; i++) cnt[i] = 0;

    ll tot = 0;

    for (ll i = 0; i < n; i++) {
        ll val = 0;

        for (const ll j : divs[a[i]]) rep[j] = cnt[j];

        for (ll j = divs[a[i]].size() - 1; j >= 0; j--) {
            val += divs[a[i]][j] * rep[divs[a[i]][j]];

            for (const ll k : divs[divs[a[i]][j]]) rep[k] -= rep[divs[a[i]][j]];
        }

        tot += val * (n - i - 1);

        for (const ll j : divs[a[i]]) cnt[j]++;
    }

    cout << tot << "\n";
}

int main() {
    io

    for (ll i = 1; i <= 100000; i++) for (ll j = i; j <= 100000; j += i) divs[j].pb(i);

    tc

    return 0;
}