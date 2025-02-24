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

#define tc ll t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define square(i) (i * i)
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

ll gcd(const ll& a, const ll& b) {
    if (a == 0) return b;

    return gcd(b % a, a);
}

bool s(const pii& a, const pii& b) {
    return sqrt(square(a.first) + square(a.second)) < sqrt(square(b.first) + square(b.second));
}

pii slope(const pii& a) {
    const ll c = gcd(a.first, a.second);

    pii s = a; s.first /= c; s.second /= c;

    if (s.second < 0) {
        s.first = -s.first;
        s.second = -s.second;
    }

    return s;
}

void solve() {
    ll n {}; cin >> n;

    vpii ab (n); for (ll i {0}; i < n; ++i) cin >> ab[i].first >> ab[i].second; sort(ab.begin(), ab.end(), s); reverse(ab.begin(), ab.end());

    map<tuple<bool, pii>, pii> m {}; for (auto i : ab) m[{(i.second > 0), slope(i)}] = i;

    pii f {0, 0}; for (auto i : m) if (s(f, i.second)) f = i.second; cout << f.first << " " << f.second << "\n";
}

int main() {
    io

    solve();

    return 0;
}