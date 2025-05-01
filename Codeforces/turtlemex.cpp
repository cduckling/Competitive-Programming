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
#define f first
#define s second

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
typedef map<ll, vector<ll>> mivi;

#define sum(n) (((n) * (n + 1)) / 2)

ll mex(const ll val, const vi& a) {
    ll mex = 0; for (ll i = 1; i < a.size(); i++) {
        if (mex == a[i]) mex++;
        if (mex == val) mex++;
        if (mex == a[i]) mex++;
    }

    return mex;
}

void solve() {
    ll n, m; cin >> n >> m;

    vvi a (n + 1); for (ll i = 1; i <= n; i++) {
        ll l; cin >> l;

        a[i].resize(l + 1);

        for (ll j = 1; j <= l; j++) cin >> a[i][j];

        sort(all(a[i]));
    }

    vpii op (n + 1); for (ll i = 1; i <= n; i++) {
        const ll bef = mex(-1, a[i]);
        const ll aft = mex(bef, a[i]);

        op[i] = {bef, aft};
    }

    mivi out, in; for (ll i = 1; i <= n; i++) out[op[i].f].pb(op[i].s), in[op[i].s].pb(op[i].f);

    vi ver; for (ll i = 1; i <= n; i++) ver.pb(op[i].f), ver.pb(op[i].s); sort(all(ver), greater<ll>());
    
    mii dp; for (const ll i : ver) {
        if (dp[i]) continue;

        queue<ll> q; q.push(i); dp[i] = i;

        while (!q.empty()) {
            const ll cur = q.front(); q.pop();

            for (const ll j : in[cur]) if (dp[j] == 0) dp[j] = i, q.push(j);
        }
    }

    ll ok = 0; for (ll i = 1; i <= n; i++) ok = max(ok, op[i].f); for (ll i = 1; i <= n; i++) if (out[op[i].f].size() > 1) ok = max(ok, dp[op[i].f]);

    ll ans = ok * min(ok + 1, m + 1) + sum(m) - sum(min(ok, m));

    for (ll i = 1; i <= n; i++) if (op[i].f <= m) {
        if (op[i].f > ok) {
            ans -= op[i].f;
            ans += max(op[i].f, dp[op[i].f]);
        } else {
            ans -= ok;
            ans += max(ok, dp[op[i].f]);
        }
    }
    
    cout << ans << "\n";
}

int main() {
    io
    tc

    return 0;
}