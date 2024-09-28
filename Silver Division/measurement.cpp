#include <iostream>
#include <array>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int n {}, g {};

bool s (array<int, 3> a, array<int, 3> b) {
    return a[0] < b[0];
}
array<int, 3> entries[100000];

map<int, int> outputs {};

pair<set<int>, int> highest {{}, 0};

int changes {0};

int main() {
    freopen("measurement.in", "r", stdin); freopen("measurement.out", "w", stdout);

    cin >> n >> g;

    for (int i {0}; i < n; ++i) {
        cin >> entries[i][0] >> entries[i][1] >> entries[i][2];
        outputs[entries[i][1]] = g;
    }
    sort(entries, entries + 100000, s);

    for (int i {100000 - n}; i < 100000; ++i) {
        highest.first.insert(entries[i][1]);
        highest.second = g;
    }

    for (int i {100000 - n}; i < 100000; ++i) {
        set<int> display {};
        int cow {entries[i][1]}, measurement {entries[i][2]};
        outputs[cow] += measurement;

        if (entries[i][2] >= 0) {
            if (highest.first.count(cow)) {
                display.insert(cow);
                highest.second = outputs[cow];
            } else {
                if (outputs[cow] > highest.second) {
                    display.insert(cow);
                    highest.second = outputs[cow];
                } else if (outputs[cow] == highest.second) {
                    display = highest.first;
                    display.insert(cow);
                }
            }
        } else {
            if (highest.first.count(cow) && highest.first.size() == 1) {
                int h {0};
                for (auto output: outputs) {
                    h = max(h, output.second);
                }
                for (auto output: outputs) {
                    if (output.second == h) {display.insert(output.first);}
                }
                highest.second = h;
            }
        }

        if (display.empty()) {display = highest.first;}

        if (display != highest.first) {
            ++changes;
            highest.first = display;
        }
    }

    cout << changes;
}