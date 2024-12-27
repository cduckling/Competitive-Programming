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

ll sqrt(const ll& n) {
    pair<ll, ll> r {0, 1e10};

    while (r.first != r.second) {
        ll mid = (r.first + r.second + 1) / 2;

        if (mid * mid <= n) {
            r.first = mid;
        } else {
            r.second = mid - 1;
        }
    }

    return r.first;
}

int main() {
    io

    ll n {}; cin >> n;
    cout << sqrt(n);
}