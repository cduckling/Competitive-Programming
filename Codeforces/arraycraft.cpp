#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef vector<vector<ll>> matrix;

void solve() {
    ll n {}, x {}, y {}; cin >> n >> x >> y;

    vector<ll> a (n + 1, -1); fill(a.begin() + y, a.begin() + x + 1, 1);

    ll v = {-1};
    for (ll i {y - 1}; i >= 1; --i) {a[i] = v; v *= -1;}

    v = {-1};
    for (ll i {x + 1}; i <= n; ++i) {a[i] = v; v *= -1;}

    for (ll i {1}; i <= n; ++i) {cout << a[i] << " ";}

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}