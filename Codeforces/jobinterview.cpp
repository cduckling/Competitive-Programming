#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

pair<ll, ll> binarysearch(ll i, ll n, ll m, const vector<ll>& p, const vector<ll>& t) {
    pair<ll, ll> x {1, n + m + 2};

    while (x.first != x.second) {
        ll mid = (x.first + x.second) / 2;

        if (mid < i) {
            if (p[mid] < n) {
                x.first = mid + 1;
            } else {
                x.second = mid;
            }
        } else {
            if (p[mid] < n + (p[i] != p[i - 1] ? 1 : 0)) {
                x.first = mid + 1;
            } else {
                x.second = mid;
            }
        }
    }

    pair<ll, ll> y {1, n + m + 2};

    while (y.first != y.second) {
        ll mid = (y.first + y.second) / 2;

        if (mid < i) {
            if (t[mid] < m) {
                y.first = mid + 1;
            } else {
                y.second = mid;
            }
        } else {
            if (t[mid] < m + (t[i] != t[i - 1] ? 1 : 0)) {
                y.first = mid + 1;
            } else {
                y.second = mid;
            }
        }
    }

    return {(x.first == i ? x.first + 1 : x.first), (y.first == i ? y.first + 1 : y.first)};
}

void solve() {
    ll n, m; cin >> n >> m;

    vector<ll> programmers (n + m + 2); for (ll i {1}; i <= n + m + 1; ++i) cin >> programmers[i];
    vector<ll> testers (n + m + 2); for (ll i {1}; i <= n + m + 1; ++i) cin >> testers[i];

    vector<ll> b (n + m + 2), p (n + m + 2), t (n + m + 2); for (ll i {1}; i <= n + m + 1; ++i) {
        b[i] = max(programmers[i], testers[i]);

        p[i] = (b[i] == programmers[i]);
        t[i] = (b[i] == testers[i]);

        p[i] += p[i - 1]; t[i] += t[i - 1]; b[i] += b[i - 1];
        programmers[i] += programmers[i - 1]; testers[i] += testers[i - 1];
    }

    for (ll i {1}; i <= n + m + 1; ++i) {
        if (n == 0) {
            cout << testers[n + m + 1] - (testers[i] - testers[i - 1]) << " ";
        } else if (m == 0) {
            cout << programmers[n + m + 1] - (programmers[i] - programmers[i - 1]) << " ";
        } else {
            pair<ll, ll> r {binarysearch(i, n, m, p, t)};

            ll s {b[min(r.first, r.second)]};

            if (r.first == min(r.first, r.second)) {
                s += testers[n + m + 1] - testers[min(r.first, r.second)];
            } else {
                s += programmers[n + m + 1] - programmers[min(r.first, r.second)];
            }

            if (i < min(r.first, r.second)) {
                s -= max(programmers[i] - programmers[i - 1], testers[i] - testers[i - 1]);
            } else {
                if (r.first == min(r.first, r.second)) {
                    s -= testers[i] - testers[i - 1];
                } else {
                    s -= programmers[i] - programmers[i - 1];
                }
            }

            cout << s << " ";
        }
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}