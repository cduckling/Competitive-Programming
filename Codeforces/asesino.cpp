#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

bool query(const int a, const int b) {
    cout << "? " << a << " " << b << endl;
    bool c {}; cin >> c; return c;
}

void imp(int i) {
    cout << "! " << i << endl;
}

void solve() {
    int n {}; cin >> n;

    for (int i {1}; i <= n - (n % 2 != 0); i += 2) if (query(i, i + 1) != query(i + 1, i)) {
            if (i == 1) {
                if (query(1, 3) != query(3, 1)) {
                    imp(1);
                } else {
                    imp(2);
                }
            } else {
                if (query(1, i) != query(i, 1)) {
                    imp(i);
                } else {
                    imp(i + 1);
                }
            }

            return;
        }

    if (n % 2 != 0) imp(n);
}

int main() {
    io
    tc

    return 0;
}