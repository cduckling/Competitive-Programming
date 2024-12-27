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

const ll m = 1e9 + 7;

ll inverses[100000001];

ll inverse(ll x) {
    if (inverses[x] != -1) return inverses[x];

    inverses[x] = x <= 1 ? x : m - m / x * inverse(m % x) % m;
    return inverses[x];
}

int main() {
    io

    inverses[1] = 1; for (int i {2}; i <= 100000000; ++i) inverses[i] = -1;

    int n {}; cin >> n;
    for (int i {2}; i <= n; ++i) cout << inverse(i) << " ";
}