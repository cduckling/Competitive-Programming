#include <iostream>
using namespace std;

#define pasture(cow) pasture[cow.first][cow.second]

pair<int, bool> pasture[3000][3000];

pair<int, int> neighbor (pair<int, int> cow) {
    for (int i {0}; i < 4; ++i) {
        pair<int, int> adjacent = cow;

        switch (i) {
            case 0: ++adjacent.first; break;
            case 1: --adjacent.first; break;
            case 2: ++adjacent.second; break;
            case 3: --adjacent.second; break;
        }

        if (!pasture(adjacent).second) {return adjacent;}
    }
}

int uncomfortable(pair<int, int> cow) {
    int additional {0};

    if (pasture(cow).first == 3) {
        pair<int, int> adjacent = neighbor(cow);
        pasture(adjacent).second = true;
        additional += 1 + uncomfortable(adjacent);
    }

    for (int i {0}; i < 4; ++i) {
        pair<int, int> adjacent = cow;

        switch (i) {
            case 0: ++adjacent.first; break;
            case 1: --adjacent.first; break;
            case 2: ++adjacent.second; break;
            case 3: --adjacent.second; break;
        }

        ++pasture(adjacent).first;

        if (pasture(adjacent).second && pasture(adjacent).first == 3) {
            pair<int, int> a = neighbor(adjacent);
            pasture(a).second = true;
            additional += 1 + uncomfortable(neighbor(adjacent));
        }
    }

    return additional;
}

int main() {
    int n {}; cin >> n;

    int additional {0};

    for (int i {0}; i < n; ++i) {
        pair<int, int> cow {};
        cin >> cow.first >> cow.second;
        cow.first += 1000; cow.second += 1000;

        if (pasture(cow).second) {
            --additional;
        } else {
            pasture(cow).second = true;
            cout << uncomfortable(cow) << "\n";
        }

        //cout << additional << "\n";
    }
}