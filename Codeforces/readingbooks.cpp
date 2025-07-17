#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

ll n {}, k {};

int main() {
    io

    cin >> n >> k;

    vector<ll> books[4]; for (ll i {0}; i < n; ++i) {
        ll t {}, a {}, b {}; cin >> t >> a >> b;

        books[2 * a + b].push_back(t);
    }

    sort(books[1].begin(), books[1].end()); sort(books[2].begin(), books[2].end()); sort(books[3].begin(), books[3].end());

    vector<ll> a {}; for (ll i {0}; i < min(books[1].size(), books[2].size()); ++i) {
        a.push_back(books[1][i] + books[2][i]);
    }
    vector<ll> b {a}; for (ll i : books[3]) {
        b.push_back(i);
    } sort(b.begin(), b.end());

    if (b.size() < k) {
        cout << -1;
    } else {
        ll r{0};
        for (ll i{0}; i < k; ++i) {
            r += b[i];
        }
        cout << r;
    }
}