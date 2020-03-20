#include<bits/stdc++.h>

using namespace std;

struct Node{
      int left, right;
      long long res, lazy;
      Node *p1, *p2;
};
Node *st;
 
Node *CreateNode(int l, int r, long long sum)
{
      Node *p; p = new Node;
      p->lazy = p->res = sum;
      p->left = l; p-> right = r;
      p->p1 = p->p2 = NULL;
      return p;
}
void down(Node *id)
{
      int mid = (id->left + id->right) >> 1;
      if (id->p1 == NULL) id->p1 = CreateNode(id->left, mid, 0); 
      if (id->p2 == NULL) id->p2 = CreateNode(mid+1, id->right, 0); 
      
      Node *a = id->p1, *b = id->p2;
      a->res += id->lazy; a->lazy+= id->lazy;
      b->res += id->lazy; b->lazy+= id->lazy;
 
      id->lazy = 0;
 
}
void update(Node *id, int u, int v, int c)
{
      if (id->left > v || id->right < u) return;
      if (u <= id->left && id->right <= v) {
            id->lazy += c;
            id->res += c;
            return;
      }
      down(id);
      update(id->p1, u, v, c);
      update(id->p2, u, v, c);
 
      Node *a = id->p1, *b = id->p2;
      id->res = max(a->res, b->res);
}
long long get_ans(Node *id, int u, int v)
{
      if (id->left > v || id->right < u) return -1;
      if (u <= id->left && id->right <= v) return id->res;
      down(id);
      return max(get_ans(id->p1, u, v), get_ans(id->p2, u, v));
}
 
int main()
{
      int n, q, u, v, c, t; 
      cin >> n >> q;
      st = CreateNode(1, n, 0);
 
      while (q--){
            cin >> t;
            if (t) {
                  cin >> u >> v;
                  cout << get_ans(st, u, v) << "\n";
            } else {
                  cin >> u >> v >> c;
                  update(st, u, v, c);
            }
      }
}
