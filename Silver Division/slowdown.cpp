#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int n {};
vector<double> t {}, d {};
pair<int, int> a {0, 0};
double time_ {0}, speed {1}, distance_ {0};

void timeslowdown() {distance_ += (t[a.first] - time_) / speed; time_ = t[a.first]; ++a.first; ++speed;}
void distanceslowdown() {time_ += (d[a.second] - distance_) * speed; distance_ = d[a.second]; ++a.second; ++speed;}

int main() {
    freopen("slowdown.in", "r", stdin); freopen("slowdown.out", "w", stdout);

    cin >> n;

    for (int i {0}; i < n; ++i) {char s {}; int w {}; cin >> s >> w; (s == 'T' ? t : d).push_back(w);}
    sort(t.begin(), t.end()); sort(d.begin(), d.end());

    for (int i {0}; i < n; ++i) {
        if (a.first == t.size()) {distanceslowdown();}
        else if (a.second == d.size()) {timeslowdown();}
        else if (t[a.first] - time_ > (d[a.second] - distance_) * speed) {distanceslowdown();}
        else {timeslowdown();}
    }

    const double f {(1000 - distance_) * speed + time_};
    if (f - static_cast<int>(f) < 0.5) {cout << static_cast<int>(f);} else {cout << static_cast<int>(f) + 1;}
}