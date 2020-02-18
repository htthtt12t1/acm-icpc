#include <bits/stdc++.h>

using namespace std;

struct Fenwick {
    int fenSize;
    vector <int> f;
    Fenwick() {}
    void init(int n) {
        fenSize = n;
        f.resize(n + 1, 0);
    }
    void update(int p, int val) {
        for (int i = p; i <= fenSize; i += (i &-i)) {
            f[i] += val;
        }
    }
    int get(int p) {
        int ans = 0;
        for (int i = p; i; i -= (i &-i)) {
            ans += f[i];
        }
        return ans;
    }
};
