#include <iostream>
#include <vector>
using namespace std;

#define pb(i) push_back(i)

typedef vector<int> vi;

void ops(const int l, const int r, const int next, vi& add, const vi& a) {
    if (l > r) return;

    vi A; for (int i = l; i <= r; i++) A.pb(a[i]); A.pb(next);

    vi S (A.size()); for (int i = 0; i < A.size(); i++) S[i] = i; for (int i = A.size() - 2; i >= 0; i--) if (A[S[i + 1]] > A[i]) S[i] = S[i + 1];

    int pos = S[0]; while (true) {
        add.pb(A[pos]); pos++; if (pos >= A.size()) break; pos = S[pos];
    }

    add.pop_back();
}

void solve() {
    int n; cin >> n;

    vi a (n + 1); for (int i = 1; i <= n; i++) cin >> a[i];

    vi s (n + 1); for (int i = 1; i <= n; i++) s[i] = i; for (int i = n - 1; i >= 1; i--) if (a[s[i + 1]] > a[i]) s[i] = s[i + 1];

    vi imp; int pos = s[1]; while (true) {
        imp.pb(pos); pos++; if (pos > n) break; pos = s[pos];
    }

    int start = 1; vi add;

    for (int i = 0; i < imp.size() - 1; i++) {
        ops(start, imp[i] - 1, a[imp[i + 1]], add, a);

        start = imp[i] + 1; if (add.empty()) continue;

        cout << a[imp[0]]; for (int j = 1; j <= i; j++) cout << " " << a[imp[j]]; for (const int j : add) cout << " " << j; for (int j = i + 1; j < imp.size(); j++) cout << " " << a[imp[j]]; cout << "\n"; return;
    }

    ops(start, n - 1, 0, add, a);

    cout << a[imp[0]]; for (int i = 1; i < imp.size(); i++) cout << " " << a[imp[i]]; for (const int i : add) cout << " " << i; cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t; while (t--) solve();

    return 0;
}