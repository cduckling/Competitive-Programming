#include <iostream>
#include <vector>
using namespace std;

vector<int> eratosthenes(int n) {
    vector<int> e (n + 1); e[0] = 1; e[1] = 1;

    for (int i {2}; i <= n; ++i) {
        if (e[i]) {
            continue;
        } else {
            for (int j {2 * i}; j <= n; j += i) {
                e[j] = 1;
            }
        }
    }

    return e;
}

vector<int> prime(int n) {
    vector<int> p (n + 1);  p[0] = 1; p[1] = 1;
    for (int i {2}; i <= n; ++i) {
        if (p[i]) {
            continue;
        } else {
            for (int j {i}; j <= n; j += i) {
                p[j] = i;
            }
        }
    }

    return p;
}

int main() {
    int n {}; cin >> n;

    vector<int> e {eratosthenes(n)};
    for (int i {0}; i <= n; ++i) {
        cout << e[i] << " ";
    }

    cout << "\n\n";

    vector<int> p {prime(n)}, f {}; int d {n};
    while (true) {
        if (d == p[d]) {
            f.push_back(d);
            break;
        } else {
            f.push_back(p[d]);
            d /= p[d];
        }
    }

    for (int i : f) {
        cout << i << " ";
    }
}