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
    ll w, x, v; cin >> w >> x >> v;

    pii l = {0, 0}; l.second = 1e9;

    while (l.first < l.second) {
        const ll mid = (l.first + l.second + 1) / 2;

        const ll V = mid * (x + mid) * w + mid * w * log(x + mid) * 1.0 / 3;

        if (V > v) {
            l.second = mid - 1;
        } else {
            l.first = mid;
        }
    }

    cout << l.first << "\n";
}

int main() {
    io

    solve();

    return 0;
}