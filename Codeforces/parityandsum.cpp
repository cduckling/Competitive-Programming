#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}; cin >> n;

    vector<ll> even {}, odd {};

    for (ll i {0}; i < n; ++i) {
        ll a {}; cin >> a;

        if (a % 2 == 0) {
            even.push_back(a);
        } else {
            odd.push_back(a);
        }
    }

    sort(even.begin(), even.end()); sort(odd.begin(), odd.end());

    if (even.empty() || odd.empty()) {
        cout << 0 << "\n";
    } else {
        if (even[even.size() - 1] <= odd[odd.size() - 1]) {
            cout << even.size() << "\n";
        } else {
            ll j = 0;
            while (j < even.size() && odd[odd.size() - 1] >= even[j]) {
                odd[odd.size() - 1] += even[j]; ++j;
            }

            if (j != even.size()) {
                cout << even.size() + 1 << "\n";
            } else {
                cout << even.size() << "\n";
            }
        }
    }
}

int main() {
    io
    tc

    return 0;
}