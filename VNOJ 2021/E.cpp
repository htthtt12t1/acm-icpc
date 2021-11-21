#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
long long dp[MAXN][10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X, N;
    cin >> X >> N;
    vector<int> A;
    set<int> s;

    for(int i = 0; i < N; ++i)
    {
        int x; cin >> x;
        s.insert(x);
    }

    A.push_back(0);
    for(int x : s)
        A.push_back(x);

    N = (int) A.size() - 1;

    dp[0][0] = 1;
    for(int i = 1; i <= N; ++i)
        dp[A[i]][i] = 1;

    for(int i = 1; i <= X; ++i)
        for(int j = 1; j <= N; ++j)
           if (A[j] <= i)
                for(int k = 1; k <= j; ++k)
                    dp[i][j] += dp[i - A[j]][k];


    // for(int i = 1; i <= X; ++i)
        // for(int j = 1; j <= N; ++j)
            // cout << dp[i][j] << " \n"[j == N];

    long long ans = 0;
    for(int i = 1; i <= N; ++i)
        ans += dp[X][i];

    cout << ans;
}
 
