#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

ll binarysearch(const vector<ll>& a, ll b) {
    pair<ll, ll> interval {0, a.size()};

    while (interval.first != interval.second) {
        ll mid = (interval.first + interval.second) / 2;

        if (a[mid] < b) {
            interval.second = mid;
        } else {
            interval.first = mid + 1;
        }
    }

    return interval.first;
}

int main() {
    io

    ll n {}, k {}; cin >> n >> k; --k;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i]; sort(a.begin(), a.end(), greater<ll>()); a.push_back(0);
    vector<ll> c (n + 1); for (ll i {0}; i <= n; ++i) c[i] = (a[i] + 11) / 12;

    ll y {0}; vector<ll> jumps {};

    for (ll i {0}; i < n; ++i) {
        if (a[i] % 12 == 0) {
            jumps.push_back(12 * (c[i] - c[i + 1])); if (!jumps[jumps.size() - 1]) jumps.erase(--jumps.end());
        } else {
            y += 12;

            ll j = binarysearch(c, c[i]);
            jumps.push_back(12 * (c[i] - c[j] - 1)); if (!jumps[jumps.size() - 1]) jumps.erase(--jumps.end());
            i = j - 1;
        }
    }

    sort(jumps.begin(), jumps.end()); for (ll i {0}; i < jumps.size() - k; ++i) y += jumps[i];

    cout << y;

    return 0;
}