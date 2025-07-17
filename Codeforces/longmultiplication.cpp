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
    string x {}, y {}; cin >> x >> y;

    int r {-1};

    for (int i {0}; i < x.length(); ++i) {
        if (r == -1) {
            if (x[i] - 'A' > y[i] - 'A') {
                r = 0;
            } else if (x[i] - 'A' < y[i] - 'A') {
                r = 1;
            }
        } else {
            if (r) {
                int a {x[i] - 'A'}, b {y[i] - 'A'};
                y[i] = min(a, b) + 'A';
                x[i] = max(a, b) + 'A';
            } else {
                int a {x[i] - 'A'}, b {y[i] - 'A'};
                y[i] = max(a, b) + 'A';
                x[i] = min(a, b) + 'A';
            }
        }
    }

    cout << x << "\n" << y << "\n";
}

int main() {
    io
    tc

    return 0;
}