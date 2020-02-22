#include<bits/stdc++.h>
 
using namespace std;

const int maxn = 2e5 + 5;
int n, q, id;
typedef pair<int,int> ii;
vector<int>a[maxn];
int nChain, Chain[maxn], ChainHead[maxn], ansChain, h[maxn], nChild[maxn], par[maxn], first[maxn][2];
int mark[maxn];
ii pass[maxn];

void DFS(int u, int height = 0, int p = -1)
{
    nChild[u] = 1;
    h[u] = height;
    for(auto v: a[u]){
        if (v == p) continue;
        DFS(v, height + 1, u);
        par[v] = u;
        nChild[u] += nChild[v];
    }
}
void hld(int u)
{
    if (ChainHead[nChain] == 0) ChainHead[nChain] = u;
    Chain[u] = nChain;
    
    int next = -1;
    for(auto v: a[u]) if (v != par[u]){
        if (next == -1 || nChild[next] < nChild[v]) next = v;
    }
    if (next != -1) hld(next);
    for(auto v: a[u]) if (v != next && v != par[u]) {
        ++nChain;
        hld(v);
    }
}
void SFD(int u, int k)
{   
    int type = (k < 0);
    first[Chain[u]][type] = u;
    if (!type) pass[Chain[u]] = ii(k, id);
    else if (pass[Chain[u]].first == -k && pass[Chain[u]].second == id) {
        ansChain = Chain[u];
        return;
    }
    if (Chain[u] == 1) return;
    int v = par[ChainHead[Chain[u]]];
    SFD(v, k);
}
int lca(int u, int v)
{
    SFD(u, v); SFD(v, -v);
    int x = first[ansChain][0], y = first[ansChain][1];
    if (h[x] > h[y]) return y; else return x;
}

int main()
{
    cin >> n >> q;
    for(int i=1; i<n; ++i) {            
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS(1);
    nChain = 1; hld(1);

    for(id =1; id<=q; ++id){
        int u, v; cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}
