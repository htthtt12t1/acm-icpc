// Count how many of SQ numbers which their square digits is a prime. 
// Input: Number N and S (N, S <= 10^18)
// Output: The N_th SQ number and the position of S in lexicography order.

#include <bits/stdc++.h>

using namespace std;

string s; 
long long n, f[20][2][1500], ans;
bool p[1500];
string a = " 1 000000000000000";

long long calc(int i, int less, int sum)
{
    if (i > 16) return p[sum];
    long long &res = f[i][less][sum];
    if (res != -1) return res;
    res = 0;
    int x = 9; if (!less) x = a[i] - '0';
    for(int j=0; j<=x; ++j) res += calc(i + 1, less || (j < x), sum + j*j);
    return res;
}

void trace(int i, int less, int sum, long long s)
{
    if (i > 16) return;
    int x = 9; if (!less) x = a[i] - '0';
    for(int j=0; j<=x; ++j) 
        if (calc(i + 1, less || (j < x), sum + j*j) < s) 
            s -= calc(i + 1, less || (j < x), sum + j*j);
        else {
            ans = ans * 10 + j;
            trace(i + 1, less || (j < x), sum + j*j, s);
            return;
        } 
}
long long id(int i, int sum)
{
    if (i > 16) return 1;
    long long res = 0;
    int x = s[i] - '0';
    for(int j=0; j<x; ++j) res += calc(i + 1, 1, sum + j*j);
    return res + id(i + 1, sum + x*x);
}

bool prime(int x)
{
    for(int i=2; i<x; ++i) if (x % i == 0) return false;
    return true;
}

int main()
{
    for(int i=2; i<=1500; ++i) p[i] = prime(i);
    memset(f, 255, sizeof(f));
    cin >> n >> s;
    while (s.length() <= 16) s = '0' + s;
    trace(1, 0, 0, n);
    cout << ans << "\n";
    cout << id(1, 0);
}
