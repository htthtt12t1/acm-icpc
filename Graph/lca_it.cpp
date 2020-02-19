#include<bits/stdc++.h>
 
using namespace std;

int T1, T2, n, q;
vector<vector<int> >a;
vector<int> A, B, postnum, prevnum, st;

void DFS(int u, int p = -1)
{
    prevnum[u] = ++T1;
    for(auto v: a[u]) if (v != p){
        DFS(v, u);
    }
    postnum[u] = ++T2;
    A[prevnum[u]] = postnum[u];
    B[postnum[u]] = u;
}
void update(int id, int l, int r)
{
    if (l == r){
        st[id] = A[l];
        return;
    }
    int mid = (l + r) >> 1;
    update(id*2, l, mid);
    update(id*2+1, mid+1, r);
    st[id] = max(st[id*2], st[id*2+1]);
}
int lca(int id, int l, int r, int u, int v)
{
    if (l == r ) {
        if (A[l] >= v) return B[A[l]];
        return -1;
    }
    int x = st[id*2], y = st[id*2+1], mid = (l + r) >> 1;
    if (mid+1 <= u && v <= y) {
        int t = lca(id*2+1, mid+1, r, u, v);
        if (t != -1) return t;
    }
    int t = lca(id*2, l, mid, u, v);
    if (t != -1) return t;
    return -1;
}
int main()
{
    cin >> n >> q;
    a.resize(n+1); 
    A.resize(n+1); B.resize(n+1); postnum.resize(n+1); prevnum.resize(n+1);
    st.resize(4*n+1);

    for (int i=1; i<n; ++i){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS(1);
    update(1, 1, n);
    while (q--){
        int u, v; cin >> u >> v;
        int x = min(prevnum[u], prevnum[v]), y = max(postnum[u], postnum[v]);
        cout << lca(1, 1, n, x, y) << "\n";
    }
}
