#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}, k {}; cin >> n >> k;

    vector<int> a {n}; int o {0};

    while (a.size() < n) {
        ++o;

        a[0] -= k;
        a[0] += 1;

        for (int i {1}; i < k; ++i) {
            a.push_back(1);
        }
    }

    cout << o << "\n";
}

int main() {
    io
    tc

    return 0;
}