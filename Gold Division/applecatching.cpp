#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

#define fir first
#define sec second
#define eb(a, b, c) emplace_back(a, b, c)
#define all(a) a.begin(), a.end()

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef tuple<int, int, int> tiii;
typedef vector<tuple<int, int, int>> vtiii;

void solve() {
    int n; cin >> n;

    vtiii cow, apple; for (int i = 1; i <= n; i++) {
        int q, time, pos, num; cin >> q >> time >> pos >> num;

        (q == 1 ? cow : apple).eb(pos, time, num);
    } sort(all(cow)), sort(all(apple));

    int take = 0;

    for (int i = 0; i < cow.size(); i++) {
        vpii APPLE; for (int j = 0; j < apple.size(); j++) if (get<2>(apple[j]) && abs(get<0>(apple[j]) - get<0>(cow[i])) <= get<1>(apple[j]) - get<1>(cow[i])) APPLE.emplace_back(get<1>(apple[j]) + get<2>(apple[j]), j); sort(all(APPLE));

        int j = 0; while (j < APPLE.size() && 0 < get<2>(cow[i])) {
            const int rem = min(get<2>(cow[i]), get<2>(apple[APPLE[j].sec]));

            take += rem; get<2>(cow[i]) -= rem, get<2>(apple[APPLE[j].sec]) -= rem; j++;
        }
    }

    cout << take << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}