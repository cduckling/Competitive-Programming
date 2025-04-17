#include <iostream>
#include <set>
#include <string>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}

typedef long long ll;
typedef pair<int, int> pii;

void query(pii a) {
    cout << "? " << a.first << " " << a.second << endl; fflush(stdout);
}

void path(const int& d, set<pii>& e, set<int>& v) {
    pii q {1, d}; int m {};

    while (!v.count(q.first)) {
        query(q); cin >> m;

        if (m == q.first) {
            e.insert({min(q.first, q.second), max(q.first, q.second)});
            v.erase(q.second);
            return;
        }

        q.first = m;
    }

    while (q.first != q.second) {
        pii q_ {q};

        query(q_); cin >> m;

        while (m != q_.first) {
            q_.second = m; query(q_); cin >> m;
        }

        e.insert({min(q_.first, q_.second), max(q_.first, q_.second)});

        v.erase(q_.second);

        q.first = q_.second;
    }
}

void solve() {
    int n {}; cin >> n;

    set<pii> e {}; set<int> v {}; for (int i {1}; i <= n; ++i) v.insert(i);

    path(2, e, v); v.erase(1);

    while (!v.empty()) {
        path(*v.begin(), e, v);
    }

    string r = "!";

    for (auto i : e) {
        r += " " + to_string(i.first) + " " + to_string(i.second);
    }

    cout << r << endl; fflush(stdout);
}

int main() {
    tc

    return 0;
}