#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

#define square(a) ((a) * (a))

int n {};

vector<pair<int, int>> cows {};
map<pair<int, int>, bool> visited {};

void dfs(pair<int, int> cow, int x) {
    if (visited[{cow.first, cow.second}]) {
        return;
    } else {
        visited[{cow.first, cow.second}] = true;

        for (pair<int, int> c : cows) {
            int a {c.first}, b {c.second};

            if (square(cow.first - a) + square(cow.second - b) <= x) {
                dfs({a, b}, x);
            }
        }
    }
}

bool pass(int x) {
    visited.clear();

    dfs(cows[0], x);

    for (pair<int, int> cow: cows) {
        int a {cow.first}, b {cow.second};

        if (!visited[{cow.first, cow.second}]) {
            return false;
        }
    }

    return true;
}

int main() {
    freopen("moocast.in", "r", stdin); freopen("moocast.out", "w", stdout);

    cin >> n;

    for (int i {0}; i < n; ++i) {
        pair<int, int> cow {};
        cin >> cow.first >> cow.second;
        cows.push_back(cow);
    }

    pair<int, int> x {0, 1250000000};

    while (x.first != x.second) {
        int median {(x.first + x.second) / 2};

        if (pass(median)) {
            x.second = median;
        } else {
            x.first = median + 1;
        }
    }

    cout << x.first;
}