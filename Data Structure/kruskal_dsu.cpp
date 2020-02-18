#include<bits/stdc++.h>

using namespace std;
vector<int> h, root;

int getroot(int u)
{
    if (root[u] == u) return u;
    return getroot(root[u]);
}
void match(int x, int y)
{
    root[x] = y;
    h[y] = max(h[y], h[x]+1);
}
bool componet(int u, int v)
{
    int x = getroot(u), y = getroot(v);
    if (x == y) return false;
    if (h[u] > h[v]) match(v, u); else match(u, v);
    return true; 
}
int main()
{   
    int n, m, u, v;
    cin >> n >> m;
    h.resize(n+1); root.resize(n+1);
    
    for(int i=1; i<=n; ++i) root[i] = i;
    for(int i=1; i<=m; ++i) {
        int u, v; 
        cin >> u >> v;
        if (componet(u, v)) cout << "No\n";
        else cout << "Yes\n";
    }
    
}
