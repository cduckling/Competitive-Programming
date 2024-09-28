#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}, x {}; cin >> n >> x;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) {
        cin >> a[i];
    }

    ll segments {0}; set<ll> d {a[0]};

    for (ll i {0}; i < n; ++i) {
        if (d.count(a[i]) == 1) {
            ++segments; d.clear();

            if (x % a[i] == 0) {
                d.insert(x / a[i]);
            }
        } else if (x % a[i] == 0) {
            for (const ll& d_ : d) {
                if (d_ % a[i] == 0) {
                    d.insert(d_ / a[i]);
                }
            }

            d.insert(x / a[i]);
        }
    }

    cout << segments << "\n";
}

int main() {
    io
    tc

    return 0;
}