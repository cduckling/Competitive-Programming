#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int main() {
    io

    int n {}; cin >> n;

    ll photos {0};

    vector<vector<int>> pasture (n + 1, vector<int> (n + 1)); for (int i {1}; i <= n; ++i)  {
        for (int j {1}; j <= n; ++j) cin >> pasture[i][j];
    }

    vector<vector<int>> a (n + 1, vector<int> (n + 1)); for (int i {1}; i <= n; ++i)  {
        for (int j {1}; j <= n; ++j) { a[i][j] = (pasture[i][j] == 100); a[i][j] += a[i][j - 1]; }
    }
    vector<vector<int>> b (n + 1, vector<int> (n + 1)); for (int i {1}; i <= n; ++i)  {
        for (int j {1}; j <= n; ++j) { b[i][j] = (pasture[i][j] < 100); b[i][j] += b[i][j - 1]; }
    }

    vector<vector<int>> a_ (n + 1, vector<int> (n + 1, n + 1)); for (int i {1}; i <= n; ++i)  {
        for (int j {1}; j <= n; ++j) {
            a_[i][a[i][j]] = min(a_[i][a[i][j]], j);
        }
    }
    vector<vector<int>> b_ (n + 1, vector<int> (n + 1, n + 1)); for (int i {1}; i <= n; ++i)  {
        for (int j {1}; j <= n; ++j) {
            b_[i][b[i][j]] = min(b_[i][b[i][j]], j);
        }
    }

    for (int i {1}; i <= n; ++i) {
        for (int j {1}; j <= n; ++j) {
            if (pasture[i][j] < 100) continue;

            int p = max(a_[i][1 + a[i][j - 1]], j);
            int q = max(b_[i][1 + b[i][j - 1]], j);

            if (p < q) photos += q - p;

            for (int k {i + 1}; k <= n; ++k) {
                p = max(min(p, a_[k][1 + a[k][j - 1]]), j);
                q = max(min(q, b_[k][1 + b[k][j - 1]]), j);

                if (p < q) photos += q - p;
            }
        }
    }

    cout << photos;

    return 0;
}