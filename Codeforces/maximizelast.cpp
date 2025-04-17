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
    ll n {}; cin >> n;
    
    ll g {0};
    for (ll i {0}; i < n; ++i) {
        ll j {}; cin >> j;
        
        if (i % 2 == 0) {
            g = max(g, j);
        }
    }
    
    cout << g << "\n";
}

int main() {
    io
    tc

    return 0;
}