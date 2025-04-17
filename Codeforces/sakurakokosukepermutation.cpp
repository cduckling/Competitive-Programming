#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i]; for (int i {0}; i < n; ++i) --a[i]; int s {0};

    vector<int> m (n); for (int i {0}; i < n; ++i) m[a[i]] = i;

    for (int i {0}; i < n; ++i) {
        if (a[i] == i) {
            continue;
        } else if (a[a[i]] == i) {
            continue;
        } else {
            ++s;

            int j = a[i], k = m[i];

            swap(m[a[j]], m[a[k]]);
            swap(a[j], a[k]);
        }
    }

    cout << s << "\n";
}

int main() {
    io
    tc

    return 0;
}