#include <iostream>
#include <vector>
using namespace std;

int n {};

int d[1000001];

int main() {
    cin >> n;

    int a[n]; for (int i {0}; i < n; ++i) {
        cin >> a[i];
    }

    for (int i {0}; i < n; ++i) {
        for (int j {1}; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                ++d[j];

                if (a[i] / j != j) {++d[a[i] / j];}
            }
        }
    }

    for (int i {1000000}; i >= 0; --i) {
        if (d[i] >= 2) {
            cout << i; break;
        }
    }
}