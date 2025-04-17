#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}

typedef long long ll;

void solve() {
    ll n {}, k {}; cin >> n >> k;

    ll sum {0}, prefix {0}, operations {200000000000};

    vector<ll> a (n); for (ll i {0}; i < n; ++i) {
        cin >> a[i]; sum += a[i];
    } sort(a.begin(), a.end(), greater<int>());

    if (sum <= k) {
        cout << 0 << "\n";
    } else if (n == 1) {
        cout << a[0] - k << "\n";
    } else {
        for (ll i {0}; i < n - 1; ++i) {
            prefix += a[i];

            pair<ll, ll> b {0, 200000000000};
            while (b.first != b.second) {
                ll b_{(b.first + b.second) / 2};

                if (sum - (prefix - (i + 1) * (a[n - 1] - b_)) - b_ <= k) {
                    b.second = b_;
                } else {
                    b.first = b_ + 1;
                }
            }

            operations = min(operations, b.first + i + 1);
        }

        cout << min(operations, sum - k) << "\n";
    }
}

int main() {
    tc
}