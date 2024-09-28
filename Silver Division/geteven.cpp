#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
    freopen("geteven.in", "r", stdin); freopen("geteven.out", "w", stdout);

    int n {}; cin >> n;

    vector<ll> b {};
    vector<ll> e {};
    vector<ll> s {};
    vector<ll> i_ {};
    vector<ll> g {};
    vector<ll> o {};
    vector<ll> m {};

    for (int i {0}; i < n; ++i) {
        char c {}; cin >> c;
        ll v {}; cin >> v;

        switch (c) {
            case 'B': b.push_back(v); break;
            case 'E': e.push_back(v); break;
            case 'S': s.push_back(v); break;
            case 'I': i_.push_back(v); break;
            case 'G': g.push_back(v); break;
            case 'O': o.push_back(v); break;
            case 'M': m.push_back(v); break;
        }
    }

    ll f {0};

    for (ll b_ : b) {
        for (ll e_ : e) {
            for (ll s_ : s) {
                for (ll i : i_) {
                    for (ll g_ : g) {
                        for (ll o_ : o) {
                            for (ll m_ : m) {
                                if ((b_ + e_ + s_ + s_ + i + e_) * (g_ + o_ + e_ + s_) * (m_ + o_ + o_) % 2 == 0) {++f;}
                            }
                        }
                    }
                }
            }
        }
    }

    cout << f;
}