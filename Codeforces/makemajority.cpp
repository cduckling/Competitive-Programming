#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    vector<bool> a {};

    char a_ {}; cin >> a_; a.push_back((a_ == '1'));

    for (int i {1}; i < n; ++i) {
        char b {}; cin >> b;

        if (b == '1') {
            a.push_back(true);
        } else if (a[a.size() - 1]) {
            a.push_back(false);
        }
    }

    int t {0}, f {0};

    for (bool i : a) {
        if (i) {
            ++t;
        } else {
            ++f;
        }
    }

    if (f >= t) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    io
    tc

    return 0;
}