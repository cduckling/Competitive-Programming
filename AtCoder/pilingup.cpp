#include <iostream>
using namespace std;

int main() {
    int r {}; cin >> r;

    if (r <= 99) {
        cout << 100 - r;
    } else if (r <= 199) {
        cout << 200 - r;
    } else {
        cout << 300 - r;
    }
}