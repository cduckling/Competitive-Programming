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
    string s {}; cin >> s;

    if (s.size() == 1)  {
        cout << s << ((s == "a") ? "b": "a") << "\n";
    } else {
        bool b {false};

        cout << s[0];
        for (int i {1}; i < s.size(); ++i) {
            if (s[i] == s[i - 1] && !b) {
                b = true;
                cout << ((s[i] == 'a') ? "b": "a") << s[i];
            } else {
                cout << s[i];
            }
        }

        if (!b) {
            cout << ((s[s.size() - 1] == 'a') ? "b": "a");
        }

        cout << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}