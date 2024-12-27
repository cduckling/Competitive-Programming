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

ll m = 1e9 + 7;
ll factorials[1000001];
ll inverses[1000001];

ll inverse(ll x) {
    return x <= 1 ? x : m - m / x * inverse(m % x) % m;
}

int main() {
    io

    ll q {}; cin >> q;

    factorials[0] = 1;
    for (int i {1}; i <= 1000000; ++i) factorials[i] = ((factorials[i - 1] % m) * (i % m)) % m;

    inverses[0] = 1; inverses[1] = 1;
    for (int i {2}; i <= 1000000; ++i) inverses[i] = ((inverses[i - 1] % m) * (inverse(i) % m)) % m;

    for (ll i {0}; i < q; ++i) {
        ll a {}, b {}; cin >> a >> b;
        cout << ((factorials[a] * inverses[b]) % m *  inverses[a - b]) % m << "\n";
    }
}