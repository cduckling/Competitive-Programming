// Codeforces Round 945 (Div. 2)

#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}

typedef long long ll;

void solve() {
    vector<int> p (3, 0); cin >> p[0] >> p[1] >> p[2];

    if ((p[0] + p[1] + p[2]) % 2 == 0) {
        int d {0};

        for (int i {0}; i <= min(p[1], p[2]); ++i) {
            vector<int> p_ {p};
            p_[1] -= i; p_[2] -= i;

            for (int j {0}; j <= min(p_[0], p_[2]); ++j) {
                vector<int> q {p_};
                q[0] -= j; q[2] -= j;

                for (int k {0}; k <= min(q[0], q[1]); ++k) {
                    d = max(d, i + j + k);
                }
            }
        }

        cout << d << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    tc
}