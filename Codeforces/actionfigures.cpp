#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}; cin >> n;

    vector<bool> a (n + 1); for (ll i {1}; i <= n; ++i) {
        char b {}; cin >> b;

        a[i] = (b == '1');
    }

    priority_queue<ll> d {}; d.push(n);

    vector<ll> dp (n + 1); dp[n] = n;

    for (ll i {n - 1}; i >= 1; --i) {
        dp[i] = dp[i + 1] + i;

        if (a[i]) {
            if (i - 1 > d.size()) {
                d.push(i);
            } else {
                if (!d.empty()) {
                    dp[i] -= d.top(); d.pop();
                } else {
                    d.push(i);
                }
            }
        } else {
            if (!d.empty()) {
                dp[i] -= d.top(); d.pop();
            }
        }
    }

    cout << dp[1] << "\n";
}

int main() {
    io
    tc

    return 0;
}