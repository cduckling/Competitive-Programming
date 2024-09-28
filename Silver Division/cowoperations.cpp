#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int main() {
    io

    string s {}; cin >> s; s = " " + s;

    vector<int> c (s.size()), o (s.size()), w (s.size());

    for (int i {1}; i < static_cast<int>(s.size()); ++i) {
        switch(s[i]) {
            case 'C': ++c[i]; break;
            case 'O': ++o[i]; break;
            case 'W': ++w[i]; break;
        }

        c[i] += c[i - 1];
        o[i] += o[i - 1];
        w[i] += w[i - 1];
    }

    int q {}; cin >> q;

    for (int i {0}; i < q; ++i) {
        int l {}, r {}; cin >> l >> r;

        int a {c[r] - c[l - 1]}, b {o[r] - o[l - 1]}, c {w[r] - w[l - 1]};

        c %= 2; b %= 2; if (c == 1 && b == 1) {++a; c = 0; b = 0;}

        if (a % 2 != 0 && c == 0 && b == 0) {
            cout << 'Y';
        } else {
            cout << 'N';
        }
    }

    return 0;
}