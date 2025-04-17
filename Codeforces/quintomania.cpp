#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i];

    bool t = true;
    for (int i {1}; i < n; ++i) if (abs(a[i] - a[i - 1]) != 5 && abs(a[i] - a[i - 1]) != 7) t = false;

    if (t) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    io
    tc

    return 0;
}