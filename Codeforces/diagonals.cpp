#include <iostream>
#include <vector>

using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef vector<vector<int>> matrix;

void solve() {
    int n {}, k {}; cin >> n >> k;

    if (k == 0) {
        cout << 0 << "\n";
    } else {
        vector<int> a {};
        for (int i {n}; i >= 1; --i) {
            if (i == n) {
                a.push_back(n);
            } else {
                a.push_back(i);
                a.push_back(i);
            }
        }

        int d {0};

        for (int i : a) {
            if (k > i) {
                k -= i;
                ++d;
            } else if (k == i) {
                ++d;
                break;
            }
        }

        cout << d << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}