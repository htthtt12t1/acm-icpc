//https://www.spoj.com/problems/PSEGTREE/
#include<bits/stdc++.h>
 
using namespace std;
const int maxn = 1e5 + 4;
typedef pair<int,int> ii;
struct Node{
    int sum, left, right;
}; 
Node st[maxn*25];
int q, n, idNode, cnt, ver[maxn], a[maxn], num;

int get(int id, int l, int r, int u, int v)
{
    if (u <= l && r <= v) return st[id].sum;
    if (u > r || l > v) return 0;
    int mid = (l + r) >> 1;
    return get(st[id].left, l, mid, u, v) + get(st[id].right, mid+1, r, u, v); 
}
int update(int node, int l, int r, int u, int val)
{
    if (l == r) {
        ++idNode;
        st[idNode].sum = val + get(ver[num], 1, n, l, l);
        st[idNode].left = st[idNode].right = 0;
        return idNode;
    }
    int mid = (l + r) >> 1, cur = ++idNode;
    if (u <= mid) {
        st[cur].left = update(st[node].left, l, mid, u, val);
        st[cur].right = st[node].right;
    } else {
        st[cur].left = st[node].left;
        st[cur].right = update(st[node].right, mid+1, r, u, val);
    }
    st[cur].sum = st[st[cur].left].sum + st[st[cur].right].sum;
    return cur;
}
void build(int node, int l, int r)
{
    if (l == r){
        st[node].sum = a[l];
        st[node].left = st[node].right = 0;
        return;
    }
    int mid = (l + r) >> 1, x = ++idNode, y = ++idNode;
    build(x, l, mid);
    build(y, mid+1, r);
    st[node].sum = st[x].sum + st[y].sum;
    st[node].left = x; st[node].right = y;
}

int main()
{
    cin >> n; 
    for(int i=1; i<=n; ++i) cin >> a[i];
    ver[0] = idNode = 1;
    build(1, 1, n);

    cin >> q;
    while (q--){
        int t, l, r;
        cin >> t >> num >> l >> r; 
        if (--t) cout << get(ver[num], 1, n, l, r) << "\n";
        else ver[++cnt] = update(ver[num], 1, n, l, r);
    }
}
