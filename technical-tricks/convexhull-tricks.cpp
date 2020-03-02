//https://vn.spoj.com/problems/GROUP/
#include<bits/stdc++.h>
#define se second
#define fi first
using namespace std;
const int maxn = 3e5 + 4;
typedef pair<int,int> ii;
typedef pair<int, long long> il;
ii a[maxn]; vector<il> p;
long long ans;

//con trỏ pt dùng để duy trì các điểm tối ưu trong tập đường thẳng bao lồi
int pt, n;

//Điều kiện {l2 bad} khi mà l3 có giao điểm với l1 nằm bên trái giao điểm l1 với l2
bool bad(int l1, int l2, int l3)
{
    return (p[l3].se - p[l1].se)*(p[l1].fi - p[l2].fi) < 
        (p[l2].se - p[l1].se)*(p[l1].fi - p[l3].fi);
}
void push(int x, long long y)
{
    p.push_back(il(x, y));
    while (p.size() >= 3 && bad(p.size()-3, p.size()-2, p.size()-1)) {
        p.erase(p.end()-2);
    }
}
long long get(int x)
{
    if (pt < p.size())
        while (1LL*p[pt].fi*x + p[pt].se > 
            1LL*p[pt+1].fi*x + p[pt+1].se && pt < p.size()-1) ++pt;
    pt = min(pt, (int)p.size()-1);
    return 1LL*p[pt].fi*x + p[pt].se;
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i].fi >> a[i].se;
    sort(a+1, a+n+1);
    vector<ii> b;
    for(int i=1; i<=n; ++i) {
        while (b.size() && b.back().se < a[i].se) b.pop_back();
        b.push_back(a[i]);
    }
    n = b.size();
    push(b[0].se, 0);
    for(int i=0; i<n; ++i) {
        ans = get(b[i].fi);
        push(b[i+1].se, ans);
    }
    cout << ans;
}
