//https://vn.spoj.com/problems/LITES/
#include <bits/stdc++.h>
 
using namespace std;
const int N= 1e5+1;
int node[4*N], lazy[N*4], n, m;
 
void down(int idx, int l, int r){
     if (!lazy[idx]) return;
     int mid= (l+r) >> 1;
     node[idx*2]= (mid-l+1)- node[idx*2];
     lazy[idx*2]= (lazy[idx*2]+1) %2;
     node[idx*2+1]= (r-mid) -node[idx*2+1];
     lazy[idx*2+1]= (lazy[idx*2+1]+1) %2;
     lazy[idx]= 0;
}
void Rebuild(int idx, int l, int r, int u, int v){
     if (l> v|| r< u) return;
     if (u<=l&& r<=v){
          node[idx]= r-l+1-node[idx];
          lazy[idx]= (lazy[idx]+1) %2;
          return;
     }
     down(idx, l, r);
     int mid= (l+r) >> 1;
     Rebuild(idx*2, l, mid, u, v);
     Rebuild(idx*2+1,  mid+1, r, u, v);
     node[idx]= node[idx*2+1]+ node[idx*2];
}
int get_ans(int idx, int l, int r, int u, int v){
     if (l> v|| r<u) return 0;
     if (u<=l&& r<=v) return node[idx];
     down(idx, l, r);
     int mid= (l+r) >> 1;
     return get_ans(idx*2, l, mid, u, v)+ get_ans(idx*2+1, mid+1, r, u, v);
}
 
int main(){
     cin >> n  >> m;
     for (int i=1; i<=m; i++){
          int q, u, v;
          cin >> q >> u >> v;
          if (!q) Rebuild(1, 1, n, u, v);
          else cout << get_ans(1, 1, n, u, v) << endl;
     }
     return 0;
}
