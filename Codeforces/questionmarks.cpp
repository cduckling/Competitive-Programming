#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef vector<vector<int>> matrix;

void solve() {
    int n {}; cin >> n;

    string t {}; cin >> t;

    int a {0}, b {0}, c {0}, d {0};
    for (char t_ : t) {
        if (t_ == 'A') {
            ++a;
        } else if (t_ == 'B') {
            ++b;
        } else if (t_ == 'C') {
            ++c;
        } else if (t_ == 'D') {
            ++d;
        }
    }


    cout << min(a, n) + min(b, n) + min(c, n) + min(d, n) << "\n";
}

int main() {
    io
    tc

    return 0;
}