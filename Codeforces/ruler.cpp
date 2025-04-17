#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    pair<int, int> x {2, 999};

    while (x.first != x.second) {
        int a = (2 * x.first + x.second) / 3, b = (x.first + 2 * x.second) / 3;

        cout << "? " << a << " " << b << endl;

        int area {}; cin >> area;

        if (area == a * b) {
            x.first = b + 1;
        } else if (area == (a + 1) * (b + 1)) {
            x.second = a;
        } else if (area == (a + 1) * b) {
            x.first = b + 1;
            x.second = a;
        } else {
            x.first = a + 1;
            x.second = b;
        }
    }

    cout << "! " << x.first << endl;
}

int main() {
    io
    tc

    return 0;
}