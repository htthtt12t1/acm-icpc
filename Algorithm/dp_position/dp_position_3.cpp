#include <bits/stdc++.h>

using namespace std;
int n, k;
long long s, f[30][2000];

long long dp(int i, int mask)
{
    if (i == n + 1) return __builtin_popcount(mask) < 2;
    long long &res = f[i][mask];
    if (res != -1) return res;
    res = 0;
    for(int j=0; j<k; ++j) 
        res += dp(i + 1, mask ^ (1 << j));
    return res;
}
void trace(int i, int mask, long long s)
{
    if (i == n + 1) return;
    for(int j=0; j<k; ++j)
        if (s > dp(i + 1, mask ^ (1 << j))) s -= dp(i + 1, mask ^ (1 << j));
    else {
        cout << char(j + 'a'); 
        trace(i + 1, mask ^ (1 << j), s);
        return;
    }
}

int main()
{
    cin >> n >> k >> s;
    memset(f, 255, sizeof(f));
    trace(1, 0, s);
    return 0;
}
