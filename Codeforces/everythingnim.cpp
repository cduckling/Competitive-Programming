#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i]; sort(a.begin(), a.end());

    int b {1}; for (int i : a) {
        if (i == b) {
            continue;
        } else if (i == b + 1) {
            ++b;
        } else {
            break;
        }
    } if (a[0] != 1) b = 0;

    for (int i {0}; i < n; ++i) a[i] = max(0, a[i] - b);

    bool c {true}; for (int i : a) {
        if (i != 0) {
            c = false; break;
        }
    }

    if (b % 2 == 0) {
        if (c) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    } else {
        if (c) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
}

int main() {
    io
    tc

    return 0;
}