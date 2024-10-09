#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int main() {
    io

    int n {}; cin >> n;

    vector<int> s (n + 1); for (int i {0}; i < n; ++i) cin >> s[i]; s[n] = 0;

    string r {}; int p {0};

    while (s[0] > 0) {
        while (s[p] > 0) {
            --s[p]; r += 'R'; ++p;
        }

        while (p >= 1) {
            if (s[p - 1] > 1 || !s[p]) {
                --s[p - 1]; r += 'L'; --p;
            } else {
                break;
            }
        }
    }

    cout << r << "\n";

    return 0;
}