#include<bits/stdc++.h>

using namespace std;
vector<vector<int> > a;
vector<int> h; 
int n, hmax, q, p[100005][20];

void DFS(int u, int height, int prev = -1)
{
    hmax = max(hmax, height);
    h[u] = height;
    for(auto v:a[u]) {
        if (v == prev) continue;
        p[v][0] = u;
        DFS(v, height+1, u);
    }
}
void InitLCA()
{
    int k; 
    memset(p, -1, sizeof(p));
    DFS(1, 0);
    k = log2(hmax);
    for(int j=1; j<=k; ++j)
        for(int i=1; i<=n; ++i) 
    if (p[i][j-1] != -1) p[i][j] = p[p[i][j-1]][j-1];
}
int GetLCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int k = log2(h[u]);
    for(int i=k; i>=0; --i) if (h[u] - (1 << i) >= h[v]) u = p[u][i];
    for(int i=k; i>=0; --i) 
        if (p[u][i] != p[v][i] && p[u][i] != -1){
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
}

int main()
{
    cin >> n >> q;
    a.resize(n+1);
    h.resize(n+1, 0);

    for(int i=1; i<n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    InitLCA();
    while (q--){
        int u, v; 
        cin >> u >> v;
        cout << GetLCA(u, v) << "\n";
    }
}
