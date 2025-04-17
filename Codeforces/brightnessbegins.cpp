#include <iostream>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

ll sqrt(const ll& n) {
    pair<ll, ll> r {0, 1e10};

    while (r.first != r.second) {
        ll mid = (r.first + r.second + 1) / 2;

        if (mid * mid <= n) {
            r.first = mid;
        } else {
            r.second = mid - 1;
        }
    }

    return r.first;
}

void solve() {
    ll k {}; cin >> k;

    if (k == 0) {
        cout << 0 << "\n"; return;
    }

    pair<ll, ll> interval {0, 1e20};

    while (interval.first != interval.second) {
        ll mid = (interval.first + interval.second) / 2;


        if (mid - sqrt(mid) >= k) {
            interval.second = mid;
        } else {
            interval.first = mid + 1;
        }
    }

    cout << interval.first << "\n";

}

int main() {
    io
    tc

    return 0;
}