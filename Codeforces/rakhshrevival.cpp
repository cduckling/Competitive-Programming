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
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<bool> vb;
typedef set<ll> si;
typedef map<ll, ll> mi;
typedef map<ll, vector<ll>> mvi;
typedef map<ll, pair<ll, ll>> mpii;
typedef map<ll, bool> mb;

void solve() {
    ll n {}, m {}, k {}; cin >> n >> m >> k;

    vb s (n); for (ll i {0}; i < n; ++i) {
        char c {}; cin >> c;
        s[i] = (c == '1');
    }

    ll con {0}, op {0};

    for (ll i {0}; i < n; ++i) {
        if (s[i]) {
            con = 0;
        } else {
            ++con;

            if (con >= m) {
                ++op; con = 0; i = i + k - 1;
            }
        }
    }

    cout << op << "\n";
}

int main() {
    io
    tc

    return 0;
}