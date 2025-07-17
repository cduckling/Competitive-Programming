#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    vector<bitset<30>> b (n - 1); for (int i {0}; i < n - 1; ++i) {
        int j {}; cin >> j; bitset<30> k (j);
        b[i] = k;
    }
    vector<bitset<30>> a (n); for (int i {0}; i < n - 1; ++i) {
        a[i] = a[i] | b[i]; a[i + 1] = a[i + 1] | b[i];
    }

    vector<int> a_ (n); for (int i {0}; i < n; ++i) {
        a_[i] = a[i].to_ullong();
    }

    bool p = true;

    for (int i {0}; i < n - 1; ++i) {
        if (b[i] != (a[i] & a[i + 1])) {
            p = false; break;
        }
    }

    if (!p) {
        cout << -1;
    } else {
        for (int i : a_) {
            cout << i << " ";
        }
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}