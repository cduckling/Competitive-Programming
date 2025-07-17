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
#define eb(a, b) emplace_back(a, b)
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
typedef vector<char> vc;
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

ll mod = 1e9 + 7;

#define prll(a) "(" << (a).fir << ", " << (a).sec << ")"

void solve() {
    ll n; cin >> n;

    vi pos (n + 1); for (ll i = 1; i <= n; i++) cin >> pos[i];

    vc dir (n + 1); dir[1] = 'R', dir[n] = 'L'; for (ll i = 2; i < n; i++) {
        if (pos[i] - pos[i - 1] <= pos[i + 1] - pos[i]) {
            dir[i] = 'L';
        } else {
            dir[i] = 'R';
        }
    }

    ll cnt = 0;

    vpii r (n + 1), l (n + 1); l[n] = {0, 1};

    for (ll i = n - 1; i >= 1; i--) {
        cnt += r[i + 1].fir + l[i + 1].fir + l[i + 1].sec, cnt %= mod;

        r[i] = r[i + 1], l[i] = l[i + 1];

        if (dir[i] == 'R') {
            r[i].fir += r[i + 1].fir + l[i + 1].fir + l[i + 1].sec, r[i].fir %= mod;
            r[i].sec += r[i + 1].sec + l[i + 1].sec, r[i].sec %= mod;
        } else {
            l[i].fir += r[i + 1].fir + l[i + 1].fir, l[i].fir %= mod;
            l[i].sec += r[i + 1].sec + l[i + 1].sec, l[i].sec %= mod;
        }

        l[i].sec++;
    }

    cout << cnt << "\n";
}

int main() {
    io

    solve();

    return 0;
}