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

ll trie[9000000][2]; ll suff[9000000];

void solve() {
    ll n; cin >> n;

    vi a (n + 1), pos (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i];

    ll inv = 0, res = 0, open = 1;

    for (ll bit = 29; bit >= 0; bit--) {
        ll good = 0, bad = 0;

        for (ll i = n; i >= 1; i--) {
            if ((a[i]&1<<bit) == 0) {
                good += suff[trie[pos[i]][1]];
            } else {
                bad += suff[trie[pos[i]][0]];
            }

            if (trie[pos[i]][(a[i]&1<<bit) > 0] == 0) trie[pos[i]][(a[i]&1<<bit) > 0] = open++; pos[i] = trie[pos[i]][(a[i]&1<<bit) > 0]; suff[pos[i]]++;
        }

        if (bad > good) res += 1<<bit; inv += min(good, bad);
    }

    cout << inv << " " << res << "\n";
}

int main() {
    io

    solve();

    return 0;
}