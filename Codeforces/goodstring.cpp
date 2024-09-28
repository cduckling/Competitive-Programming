#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    string s {}; cin >> s;

    if (s[0] == s[s.length() - 1]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    io
    tc

    return 0;
}