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

#define tc int t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<bool> vb;
typedef multiset<int> msi;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

ll mod = 1e9 + 7;

ll factorials[2000001];
ll inverses[2000001];

ll inverse(const ll& x) {
    return x <= 1 ? x : mod - mod / x * inverse(mod % x) % mod;
}

void solve() {
    int n {}, a {}, b {}; cin >> n >> a >> b;

    vi l (a), r (b); for (int i {0}; i < a; ++i) cin >> l[i]; for (int i {0}; i < b; ++i) cin >> r[i];

    if (l[0] != 1 || l[a - 1] != r[0] || r[b - 1] != n) {
        cout << 0 << "\n"; return;
    }

    ll o = factorials[n - 1] * inverses[r[0] - 1] % mod * inverses[n - 1 - r[0] + 1] % mod;

    for (int i {0}; i < a - 1; ++i) {
        o *= factorials[l[i + 1] - 2] * inverses[l[i + 1] - l[i] - 1] % mod * inverses[l[i + 1] - 2 - (l[i + 1] - l[i] - 1)] % mod; o %= mod;
        o *= factorials[l[i + 1] - l[i] - 1]; o %= mod;
    }

    for (int i {1}; i < b; ++i) {
        o *= factorials[n - r[i - 1] - 1] * inverses[r[i] - r[i - 1] - 1] % mod * inverses[n - r[i - 1] - 1 - (r[i] - r[i - 1] - 1)] % mod; o %= mod;
        o *= factorials[r[i] - r[i - 1] - 1]; o %= mod;
    }

    cout << o % mod << "\n";
}

int main() {
    io

    factorials[0] = 1; for (int i {1}; i <= 2000000; ++i) factorials[i] = factorials[i - 1] % mod * (i % mod) % mod;

    inverses[0] = 1; inverses[1] = 1; for (int i {2}; i <= 2000000; ++i) inverses[i] = inverses[i - 1] % mod * (inverse(i) % mod) % mod;

    tc

    return 0;
}