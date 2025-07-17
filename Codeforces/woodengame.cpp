#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void felling(int& r, const int& n) {
    for (int i {20}; i >= 0; --i) {
        bool a = (1<<i)&r, b = (1<<i)&n;

        if (a && b) {
            for (int j {0}; j < i; ++j) r |= (1<<j); break;
        } else if (!a && b) {
            r |= (1<<i);
        } else {
            ;
        }
    }
}

void solve() {
    int k {}; cin >> k;

    vector<int> n (k); for (int i {0}; i < k; ++i) {
        cin >> n[i]; for (int j {1}; j < n[i]; ++j) {
            int u {}; cin >> u;
        }
    } sort(n.begin(), n.end(), greater<int>());

    int r = n[0]; for (int i {1}; i < k; ++i) felling(r, n[i]); cout << r << "\n";
}

int main() {
    io
    tc

    return 0;
}