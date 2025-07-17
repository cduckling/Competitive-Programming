#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}; cin >> n;
    string s {}; cin >> s;

    if (n == 2) {
        stringstream s_; s_ << s; ll e_ {}; s_ >> e_; cout << e_ << "\n";
    } else {
        ll e {2147483647};

        for (ll i {1}; i < n; ++i) {
            vector<ll> a {};

            for (ll j {0}; j < n; ++j) {
                if (j + 1 == i) {
                    continue;
                } else if (i == j) {
                    a.push_back((s[j - 1] - '0') * 10 + (s[j] - '0'));
                } else {
                    a.push_back(s[j] - '0');
                }
            }

            ll e_ {0};

            for (ll j : a) {
                if (j == 0) {
                    e_ = 0; break;
                } else if (j == 1) {
                    continue;
                } else {
                    e_ += j;
                }
            }

            bool f {true};

            for (int j : a) {
                if (j != 1) {
                    f = false; break;
                }
            }

            if (f) {
                e = min(e, 1ll); continue;
            }

            e = min(e, e_);
        }

        cout << e << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}