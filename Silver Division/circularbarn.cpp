#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> one {1}, two {}, three {};

void solve() {
    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i];
    vector<int> t (n); for (int i {0}; i < n; ++i) {
        if (a[i] % 4 == 0) {
            t[i] = a[i] / 4;
        } else {
            if (a[i] % 4 == 1) {
                t[i] = (a[i] - one[upper_bound(one.begin(), one.end(), a[i]) - one.begin() - 1]) / 4;
            } else if (a[i] % 4 == 2) {
                t[i] = (a[i] - two[upper_bound(two.begin(), two.end(), a[i]) - two.begin() - 1]) / 4;
            } else {
                t[i] = (a[i] - three[upper_bound(three.begin(), three.end(), a[i]) - three.begin() - 1]) / 4;
            }
        }
    }

    int e {0};
    for (int i {0}; i < n; ++i) if (t[i] < t[e]) {e = i;}

    cout << "Farmer " << (a[e] % 4 == 0 ? "Nhoj" : "John") << "\n";
}

int main() {
    io

    vector<int> e (5000001); for (int i {2}; i <= 5000000; ++i) {
        if (e[i]) {
            continue;
        } else {
            for (int j {2 * i}; j <= 5000000; j += i) {
                e[j] = 1;
            }

            if (i % 4 == 1) {
                one.push_back(i);
            } else if (i % 4 == 2) {
                two.push_back(i);
            } else if (i % 4 == 3) {
                three.push_back(i);
            }
        }
    }

    tc

    return 0;
}