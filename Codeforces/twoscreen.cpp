#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    string s {}, t {}; cin >> s >> t;

    int p {0};

    for (int i {0}; i < min(s.length(), t.length()); ++i) {
        if (s[i] == t[i]) {
            ++p;
        } else {
            break;
        }
    }

    cout << s.length() + t.length() - p + (p != 0 ? 1 : 0) << "\n";
}

int main() {
    io
    tc

    return 0;
}