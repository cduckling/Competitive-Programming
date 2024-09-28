#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef vector<vector<int>> matrix;

void solve() {
    int n {}; cin >> n;
    string s {}; cin >> s;

    int north {0}, south {0}, east {0}, west {0};
    for (const char& c : s) {
        switch (c) {
            case 'N':
                ++north; break;
            case 'S':
                ++south; break;
            case 'E':
                ++east; break;
            case 'W':
                ++west; break;
        }
    }

    if (((min(north, south) >= 2) || (max(north, south)))) {
        cout << "NO\n"; return;
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}