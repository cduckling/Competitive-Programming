#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    vector<char> v = {'a', 'e', 'i', 'o', 'u'};

    if (n <= 5) {
        for (int i {0}; i < n; ++i) cout << v[i]; cout << "\n";
    } else {
        vector<int> c (5, n / 5); for (int i {0}; i < n % 5; ++i) ++c[i];

        for (int i {0}; i < c[0]; ++i) cout << v[0];
        for (int i {0}; i < c[1]; ++i) cout << v[1];
        for (int i {0}; i < c[2]; ++i) cout << v[2];
        for (int i {0}; i < c[3]; ++i) cout << v[3];
        for (int i {0}; i < c[4]; ++i) cout << v[4];
        cout << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}