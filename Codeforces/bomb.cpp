#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pll;

void solve() {
    ll n {}, k {}; cin >> n >> k;

    vector<pll> o (n); for (ll i {0}; i < n; ++i) cin >> o[i].first; for (ll i {0}; i < n; ++i) cin >> o[i].second; if (k == 0) {
        cout << 0 << "\n"; return;
    }

    ll m = 0; for (auto i : o) m = max(m, i.first);

    pair<ll, ll> min {0, 1e18}; while (min.first != min.second) {
        ll mid = (min.first + min.second) / 2;

        ll ops = 0; for (auto i : o) {
            ll a = i.first, b = i.second;

            if (a < mid) {
                ;
            } else if ((a - mid) % b == 0) {
                ops += (a - mid) / b + 1;
            } else {
                ops += (a - mid + b - 1) / b;
            }
        }

        if (ops <= k) {
            min.second = mid;
        } else {
            min.first = mid + 1;
        }
    }

    ll s {0}; for (ll i {0}; i < n; ++i) {
        ll a = o[i].first, b = o[i].second;

        ll ops {0};

        if (a < min.first) {
            continue;
        } else if ((a - min.first) % b == 0) {
            ops = (a - min.first) / b + 1;
        } else {
            ops = (a - min.first + b - 1) / b;
        }

        k -= ops;

        s += ((2 * o[i].first + (ops - 1) * -o[i].second) * (ops)) / 2;

        o[i].first -= ops * b; o[i].first = max(0ll, o[i].first);
    }

    priority_queue<pll> q {}; for (auto i : o) {q.push(i); if (i.first == 0) continue;} for (ll i {0}; i < k; ++i) {
        if (q.empty()) break;

        pll op = q.top(); q.pop();

        s += op.first; op.first -= op.second; op.first = max(0ll, op.first);

        if (op.first == 0) continue;

        q.push(op);
    }

    cout << s << "\n";
}

int main() {
    io
    tc

    return 0;
}