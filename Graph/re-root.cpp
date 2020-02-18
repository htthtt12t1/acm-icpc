#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn = 2e5 + 5;
int n, m, b[maxn];
vector<int> a[maxn];
long long dp[maxn], ans, res;
 
void DFS(int u, int p, int high)
{
    dp[u] = b[u];
    res += 1LL*b[u]*high;
    for(auto v: a[u]) if (v != p) {
        DFS(v, u, high+1);
        dp[u] += dp[v];
    }
}
void ANS(int u, int p)
{
    ans = max(ans, res);
    for(auto v: a[u]) if (v != p) {
        res -= dp[v];
        dp[u] -= dp[v];
        dp[v] += dp[u];
        res += dp[u];
        ANS(v, u);
        res -= dp[u];
        dp[v] -= dp[u];
        dp[u] += dp[v];
        res += dp[v];
    }
}
 
int main()
{
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> b[i];
    for(int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS(1, 0, 0); 
    ANS(1, 0);
    cout << ans;
}
