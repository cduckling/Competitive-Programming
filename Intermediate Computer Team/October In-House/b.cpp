#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    string s {}; cin >> s;

    int c = 0; for (char i : s) if (i == s[s.length() - 1]) ++c;

    if (c >= 3) {
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