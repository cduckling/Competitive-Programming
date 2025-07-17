#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define inf (ll) 1e18
#define fir first
#define sec second

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<vector<vector<ll>>> vvvi;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef pair<ll, ll> pii;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vector<pair<ll, ll>>> vvpii;
typedef vector<vector<vector<pair<ll, ll>>>> vvvpii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<vector<tuple<ll, ll, ll>>> vvtiii;
typedef vector<vector<vector<tuple<ll, ll, ll>>>> vvvtiii;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef set<ll> si;
typedef vector<set<ll>> vsi;
typedef vector<vector<set<ll>>> vvsi;
typedef set<pair<ll, ll>> spii;
typedef vector<set<pair<ll, ll>>> vspii;
typedef map<ll, ll> mii;
typedef map<ll, bool> mib;
typedef map<ll, double> mid;
typedef vector<map<ll, ll>> vmii;
typedef vector<map<ll, double>> vmid;
typedef vector<map<ll, bool>> vmib;

vi pref[2], suff[2];

ll area(const ll n, const ll m, const ll p, const ll q) {
    return suff[0][n + 1 - p] - pref[0][p] + suff[1][m + 1 - q] - pref[1][q];
}

void solve() {
    ll n, m; cin >> n >> m;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i]; sort(++a.begin(), a.end()); a.pb(0);
    vi b (m + 1); for (ll i = 1; i <= m; i++) cin >> b[i]; sort(++b.begin(), b.end()); b.pb(0);

    pref[0] = a, suff[0] = a; pref[1] = b, suff[1] = b;

    for (ll i = 1; i <= n; i++) pref[0][i] += pref[0][i - 1]; for (ll i = n; i >= 1; i--) suff[0][i] += suff[0][i + 1];
    for (ll i = 1; i <= m; i++) pref[1][i] += pref[1][i - 1]; for (ll i = m; i >= 1; i--) suff[1][i] += suff[1][i + 1];

    ll g = 0; for (ll i = 0; i <= min(n / 2, m); i++) g = max(g, i + min(n - 2 * i, (m - i) / 2)); cout << g << "\n";

    for (ll k = 1; k <= g; k++) {
        pii r = {max(0ll, 2 * k - m),
                 min(k, n - k)};

        while (r.fir != r.sec) {
            const ll mid = (r.fir + r.sec) / 2;

            const ll p = area(n, m, mid, k - mid), q = area(n, m, mid + 1, k - mid - 1);

            if (p > q) {
                r.sec = mid;
            } else {
                r.fir = mid + 1;
            }
        }

        cout << area(n, m, r.fir, k - r.fir) << " ";
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}