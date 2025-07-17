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

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

#define choose(a, b) ((fac[(a)] * modpow(fac[(b)], mod - 2)) % mod * modpow(fac[(a) - (b)], mod - 2) % mod)

ll mod = 998244353;

ll fac[1000001];

ll modpow(ll b, ll e) {
    b %= mod; ll r = 1;

    while (e > 0) {
        if (e % 2 == 1) r = r * b % mod;

        b = b * b % mod;
        e /= 2;
    }

    return r;
}

int main() {
    io

    ll q; cin >> q;

    fac[0] = 1; for (int i = 1; i <= 1000000; i++) fac[i] = fac[i - 1] % mod * (i % mod) % mod;

    for (ll i = 0; i < q; i++) {
        ll a, b; cin >> a >> b;
        cout << combo(a, b) % mod << "\n";
    }
}