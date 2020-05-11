//Count how many right brackets with length N and have level = K, level is the maximum of continous open bracket. 
// Input: Two number N and K (N < 100, K < N/2), a string with length N.
// Output: A number of right brackets with length N have level K and the i_th of string s in lexicorgraphy order.

#include <bits/stdc++.h>

using namespace std;
int n, k;
string s;
long long f[100][100][100];

long long calc(int i, int cnt, int lvl)
{
    if (cnt < 0 || lvl > k) return 0;
    if (i > n) return (cnt == 0 && lvl == k);
    long long &res = f[i][cnt][lvl];
    if (res != -1) return res;
    res = calc(i + 1, cnt + 1, max(cnt + 1, lvl));
    res += calc(i + 1, cnt - 1, lvl);
    return res;
}
long long id(int i, int cnt, int lvl)
{
    if (cnt < 0 || lvl > k) return 0;
    if (i > n) return (cnt == 0 && lvl == k);
    long long res = 0;
    int bonus = 1;
    if (s[i] == ')') {
        res += calc(i + 1, cnt + 1, max(cnt + 1, lvl));
        bonus = -1;
    }
    return res + id(i + 1, cnt + bonus, max(lvl, cnt + bonus));
}

int main()
{
    memset(f, 255, sizeof(f));
    cin >> n >> k >> s;
    cout << calc(1, 0, 0) << "\n";
    s = ' ' + s;
    cout << id(1, 0, 0) << "\n";
    return 0;
}
