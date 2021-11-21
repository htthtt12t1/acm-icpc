#include <bits/stdc++.h>

using namespace std;


int n,nt;
int m,d;
int st[26];
vector <vector <int> > trie;

void inp()
{
    cin >> n >> m >> d;
    d++;
    trie.resize(n*d+1);
    trie[0].resize(26,0);
}




void proc()
{
    int x,p;
    for (int i = 1; i <= n; i++)
    {
        p = x = 0;
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            if (trie[p][x] == 0)
            {
                trie[p][x] = ++nt;
                trie[nt].resize(256,0);
            }
            p = trie[p][x];
        }
    }
    bool ok = true;
    for (int i = 1; i <= m; i++)
    {
        p = x = 0;
        ok = true;
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            if (trie[p][x] == 0) ok = false;
            p = trie[p][x];
        }
        if (!ok) cout << "GOOD\n";
        else cout << "BAD\n";
    }
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
