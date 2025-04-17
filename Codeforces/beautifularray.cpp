#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n {}, k {}; cin >> n >> k;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i]; sort(a.begin(), a.end());
    map<int, vector<int>> m {}; for (int i : a) m[i % k].push_back(i);

    if (n % 2 == 0) {
        int o = 0; int b = 0;

        for (const auto& i : m) {
            if (i.second.size() % 2 != 0) ++b; if (b > 0) {
                cout << -1 << "\n"; return;
            }

            for (int j {0}; j < i.second.size(); j += 2) o += (i.second[j + 1] - i.second[j]) / k;
        }

        cout << o << "\n";
    } else {
        int o = 0, b = 0;

        for (auto i : m) {
            if (i.second.size() % 2 != 0) ++b; if (b > 1) {
                cout << -1 << "\n"; return;
            }

            if (i.second.size() % 2 == 0) {
                for (int j {0}; j < i.second.size(); j += 2) o += (i.second[j + 1] - i.second[j]) / k;
            } else {

            }
        }

        cout << o << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}