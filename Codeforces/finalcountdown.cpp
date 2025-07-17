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

    vector<int> a {}; for (int i {0}; i < n; ++i) {
        char d {}; cin >> d;

        if (d == '0' && a.empty()) {
            continue;
        } else {
            a.push_back(d - '0');
        }
    } a.insert(a.begin(), 0);

    for (int i {1}; i < a.size(); ++i) a[i] += a[i - 1];
    for (int i {static_cast<int>(a.size() - 1)}; i >= 1; --i) {a[i - 1] += a[i] / 10; a[i] %= 10;}

    for (int i {0}; i < a.size(); ++i) {
        if (i == 0 && a[0] == 0) continue;

        cout << a[i];
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}