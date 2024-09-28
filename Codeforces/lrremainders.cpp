#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}, m {}; cin >> n >> m;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i];

    string s {}; cin >> s;

    vector<int> r {}; for (int i {0}; i < n; ++i) {
        if (s[i] == 'L') {
            r.push_back(a[0] % m); a.erase(a.begin());
        } else {
            r.push_back(a[a.size() - 1] % m); a.erase(--a.end());
        }
    }

    reverse(r.begin(), r.end());

    int p {1};

    for (int i {0}; i < n; ++i) {
        a.push_back((p * r[i]) % m); p = (p * r[i]) % m;
    }

    reverse(a.begin(), a.end());
    for (int i : a) {
        cout << i << " ";
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}