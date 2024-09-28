// Codeforces Round 957 (Div. 3)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}

typedef long long ll;

void solve() {
    int n {}, m {}, k {}; cin >> n >> m >> k;

    vector<int> a (n);

    for (int i {0}; i < n; ++i) {
        a[i] = n - i;
    }

    auto it {a.begin()};

    for (int i {0}; i < n - m; ++i) {
        ++it;
    }

    reverse(it, a.end());

    for (int i : a) {
        cout << i << " ";
    }

    cout << "\n";
}

int main() {
    tc
}