#include<bits/stdc++.h>
 
using namespace std;
const int maxn = 3e5 + 4;
typedef pair<int,int> ii;
vector<ii> a[maxn];
int n, m, id, nChain, nChild[maxn], ChainHead[maxn], Chain[maxn], par[maxn], X[maxn], nPos;
int ts[maxn*4], h[maxn], pos[maxn], st[maxn*4];

typedef pair<int,int> ii;
void _accepted_by_one_hit_()
{
    #ifdef NTMA
        freopen("abc.inp", "r", stdin);
        freopen("abc.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
void DFS(int u, int height)
{
    h[u] = height;
    nChild[u] = 1;
    for(auto v: a[u]){
        if (v.first == par[u]) continue;
        par[v.first] = u;
        DFS(v.first, height+1);
        nChild[u] += nChild[v.first];
    }
}

void hld(int u, int val = -1)
{
    if (ChainHead[nChain] == 0) ChainHead[nChain] = u;
    Chain[u] = nChain;
    pos[u] = ++nPos;
    X[nPos] = val;

    int nxt = -1, valnxt = -1;
    for(auto v: a[u]) if (v.first != par[u]){
        if (nChild[v.first] > nChild[nxt] || nxt == -1) {
            nxt = v.first;
            valnxt = v.second;
        }
    }
    if (nxt != -1) hld(nxt, valnxt);
    for(auto v: a[u]){
        if (v.first != nxt && v.first != par[u]) {
            ++nChain;
            hld(v.first, v.second);
        }
    }
}
int get_ans(int u, int v)
{
    while (Chain[u] != Chain[v]) {
        int hu = ChainHead[Chain[u]], hv = ChainHead[Chain[v]];
        if (h[hu] < h[hv]) swap(u, v), swap(hu, hv);
        u = par[hu]; 
    }
    if (h[u] < h[v]) return u; else return v;
    return res;
}
int main()
{
    _accepted_by_one_hit_();

    int test; test = 1;
    while (test--){
        cin >> n;
        for(int i=1; i<n; ++i) {
            int u, v, c; cin >> u >> v >> c;
            a[u].push_back(ii(v, c));
            a[v].push_back(ii(u, c));
        }
        DFS(1, 0); nChain = 1; hld(1);
        int q; cin >> q;
        while (q--){
            int u, v; cin >> u >> v;
            cout << get_ans(u, v);
        }
    }
}
