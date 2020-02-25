#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 4;
int st[4*maxn], a[maxn], n, q;

void build(int id, int l, int r)
{
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = max(st[id*2], st[id*2+1]);
}
int get_max(int id, int l, int r, int u, int v)
{
      if (u <= l && r <= v) return st[id];
      if (u > r || l > v) return -1e9;
      int mid = (l + r) >> 1;
      return max(get_max(id*2, l, mid, u, v), get_max(id*2+1, mid+1, r, u, v));
}
int main()
{
      cin >> n >> q;
      for(int i=1; i<=n; ++i) cin >> a[i];
      build(1, 1, n);
      for(int i=1; i<=q; ++i){
            int u, v; cin >> u >> v;
            cout << get_max(1, 1, n, u, v) << endl;
      }
}
