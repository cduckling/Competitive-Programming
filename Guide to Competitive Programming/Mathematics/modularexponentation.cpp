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

ll modpow(ll b, ll e) {
    b %= m; ll r {1};
    while (e > 0) {
        if (e % 2 == 1) r = r * b % m;

        b = b * b % m;
        e /= 2;
    }

    return r;
}

int main() {
    io

    ll a {}, b {}; cin >> a >> b;
    cout << modpow(a, b);
}