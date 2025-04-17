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
typedef vector<vector<int>> matrix;

void solve() {
    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i];

    int year {a[0] + 1};

    if (n == 1) {
        cout << a[0] << "\n"; return;
    }

    for (int i {1}; i < n; ++i) {
        if (year % a[i] == 0) {
            ++year;
            continue;
        }

        year = (year - year % a[i] + a[i]) + 1;
    }

    cout << year - 1 << "\n";
}

int main() {
    io
    tc

    return 0;
}