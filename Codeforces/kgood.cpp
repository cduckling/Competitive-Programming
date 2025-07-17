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

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef set<ll> si;
typedef map<ll, ll> mii;
typedef map<ll, vector<ll>> miv;

void solve() {
    ll n {}; cin >> n;

    ll o = n; while (o % 2 == 0) o /= 2;

    ll k = 2 * (n / o); if ((k + 1) <= (2 * n) / k) {
        cout << k << "\n"; return;
    }

    for (ll i {o}; i >= 3; --i) if (i * (i + 1) / 2 <= n && n % i == 0) { cout << i << "\n"; return; }

    cout << -1 << "\n";
}

int main() {
    io
    tc

    return 0;
}