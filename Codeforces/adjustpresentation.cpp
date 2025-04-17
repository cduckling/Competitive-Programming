#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n {}, m {}, q {}; cin >> n >> m >> q;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i]; vector<int> b (m); for (int i {0}; i < m; ++i) cin >> b[i];

    vector<int> pos (n + 1, 0); for (int i {0}; i < n; ++i) pos[a[i]] = i + 1; vector<bool> pres (n + 1);

    int f {0}, p {0};

    for (int i {0}; i < m; ++i) {
        if (pos[b[i]] > f) f = pos[b[i]];

        if (!pres[b[i]]) {
            pres[b[i]] = true; if (pos[b[i]] <= f) ++p;
        }

        if (f != p) {
            cout << "TIDAK\n"; return;
        }
    }

    cout << "YA\n";
}

int main(){
    io
    tc
    
    return 0;
}