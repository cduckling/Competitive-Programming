#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n {}, t {}, p {}; cin >> n >> t >> p;

    vector<int> l (n); for (int i {0}; i < n; ++i) {
        cin >> l[i];
    } sort(l.begin(), l.end(), greater<int>());

    cout << max(t - l[p - 1], 0);
}