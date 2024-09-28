#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int mex(vector<int> &a) {
    vector<bool> f (a.size() + 1); for (int i : a) if (i <= a.size()) f[i] = 1;
    int mex = 0; while (f[mex]) ++mex;
    return mex;
}

int main() {

}