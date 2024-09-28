#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

int n {};

bool farm[2001][2001];
map<pair<pair<int, int>, pair<int, int>>, bool> fence {};

int main() {
    freopen("gates.in", "r", stdin); freopen("gates.out", "w", stdout);

    cin >> n;

    char path[n];
    for (int i {0}; i < n; ++i) {
        cin >> path[i];
    }

    pair<int, int> origin {1001, 1001};
    farm[origin.first][origin.second] = true;

    int closed {0};
    for (char direction : path) {
        pair<int, int> terminal {origin}; switch (direction) {
            case 'N':
                ++terminal.second;
                break;
            case 'E':
                ++terminal.first;
                break;
            case 'S':
                --terminal.second;
                break;
            case 'W':
                --terminal.first;
                break;
        }

        if (farm[terminal.first][terminal.second] && !fence[{origin, terminal}]) {
            ++closed;
        }

        fence[{origin, terminal}] = true;
        fence[{terminal, origin}] = true;

        farm[terminal.first][terminal.second] = true;
        origin = terminal;
    }

    cout << closed;
}