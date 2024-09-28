#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i];
    vector<int> b (n); for (int i {0}; i < n; ++i) cin >> b[i];

    vector<int> c (b); reverse(c.begin(), c.end());

    if (n == 1 || n == 2) {
        cout << "Bob\n";
    } else {
         if (a == b || a == c) {
             cout << "Bob\n";
         } else {
             cout << "Alice\n";
         }
    }
}

int main() {
    io
    tc

    return 0;
}