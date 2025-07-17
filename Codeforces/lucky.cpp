#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    vector<char> ticket (6); for (int i {0}; i < 6; ++i) cin >> ticket[i];

    int a = ticket[0] - '0' + ticket[1] - '0' + ticket[2] - '0';
    int b = ticket[3] - '0' + ticket[4] - '0' + ticket[5] - '0';

    if (a == b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    io
    tc

    return 0;
}