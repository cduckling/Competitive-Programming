#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef vector<vector<int>> matrix;

void solve() {
    int n {}; cin >> n;

    vector<char> a (n); for (int i {0}; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {cout << 0 << "\n"; return;}

    int c {0}; bool p = false;

    for (char i : a) {
        if (i == '*') {
            if (p) {break;}
            p = true;
        } else if (i == '@') {
            ++c; p = false;
        } else {
            p = false;
        }
    }

    cout << c << "\n";
}

int main() {
    io
    tc

    return 0;
}