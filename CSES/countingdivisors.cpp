#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    int d {0};
    for (int i {1}; i * i <= n; ++i) {
        if (n % i == 0) {d += 2;}
        if (i * i == n) {d -= 1;}
    }
    cout << d << "\n";
}

int main() {
    tc
}