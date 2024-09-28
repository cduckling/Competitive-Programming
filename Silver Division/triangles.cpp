#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long n {}, area {0}; constexpr long long m {1000000007};
map<long long, vector<long long>> x {}, y {};

int main() {
    freopen("triangles.in", "r", stdin); freopen("triangles.out", "w", stdout);

    cin >> n;

    pair<long long, long long> posts[n]; for (long long i {0}; i < n; ++i) {
        pair<long long, long long> post {};
        cin >> posts[i].first >> posts[i].second;

        x[posts[i].first].push_back(posts[i].second);
        y[posts[i].second].push_back(posts[i].first);
    }

    for (pair<long long, long long> post : posts) {
        long long a {0}; for (long long j : x[post.first]) {
            a += abs(post.second - j);
        }

        long long b {0}; for (long long j : y[post.second]) {
            b += abs(post.first - j);
        }

        a %= m; b %= m;

        area += a * b; area %= m;
    }

    cout << area % m;
}