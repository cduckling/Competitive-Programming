// Codeforces Round 957 (Div. 3)

#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}

typedef long long ll;

void solve() {
    int a {}, b {}, c {}; cin >> a >> b >> c;

    int bananas {a * b * c};

    for (int i {0}; i <= 5; ++i) {
        for (int j {0}; j <= 5 - i; ++j) {
            for (int k {0}; k <= 5 - i - j; ++k) {
                bananas = max(bananas, (a + i) * (b + j) * (c + k));
            }
        }
    }

    cout << bananas << "\n";
}

int main() {
    tc
}