#include <bits/stdc++.h>

using namespace std;


int n;
int a[10005][2];
int t[2];


void inp()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
}

int test(int pos)
{
    for (int i = pos; i <= n; i++)
    {
        bool ok = false;
        for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
        if (t[j] == a[i][k]) ok = true;
        if (!ok)
        {
            return i-1;
        }
    }
    return n;
}


void proc()
{
    int ans = 0;
    int x = 0;
    int tmp;
    while (x < n)
    {
        if (x == n-1)
        {
            ans++;
            break;
        }
        tmp = x;
        for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            t[0] = a[x+1][i];
            t[1] = a[x+2][j];
            tmp = max(tmp,test(x+1));
        }
        t[0] = a[x+1][0];
        t[1] = a[x+1][1];
        tmp = max(tmp,test(x+1));
        ans++;
        x = tmp;
    }
    cout << ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("disc.txt","r",stdin);
    inp();
    proc();
    return 0;
}
