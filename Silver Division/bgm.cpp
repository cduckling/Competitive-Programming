#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

ll b[7];
ll e[7];
ll s[7];
ll i[7];
ll g[7];
ll o[7];
ll m[7];

int main() {
    freopen("bgm.in", "r", stdin); freopen("bgm.out", "w", stdout);

    int n {}; cin >> n;

    for (int a {0}; a < n; ++a) {
        pair<char, int> variable {'A', 0}; cin >> variable.first >> variable.second;

        variable.second %= 7;
        if (variable.second < 0) {variable.second += 7;}

        if (variable.first == 'B') {
            ++b[variable.second];
        } else if (variable.first == 'E') {
            ++e[variable.second];
        } else if (variable.first == 'S') {
            ++s[variable.second];
        } else if (variable.first == 'I') {
            ++i[variable.second];
        } else if (variable.first == 'G') {
            ++g[variable.second];
        } else if (variable.first == 'O') {
            ++o[variable.second];
        } else {
            ++m[variable.second];
        }
    }

    ll ways {0};

    for (int b_ {0}; b_ < 7; ++b_) {
        for (int e_ {0}; e_ < 7; ++e_) {
            for (int s_ {0}; s_ < 7; ++s_) {
                for (int i_ {0}; i_ < 7; ++i_) {
                    for (int g_ {0}; g_ < 7; ++g_) {
                        for (int o_ {0}; o_ < 7; ++o_) {
                            for (int m_ {0}; m_ < 7; ++m_) {
                                if (((b_ + e_ + s_ + s_ + i_ + e_) * (g_ + o_ + e_ + s_) * (m_ + o_ + o_)) % 7 == 0) {
                                    ways += b[b_] * e[e_] * s[s_] * i[i_] * g[g_] * o[o_] * m[m_];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ways;
}