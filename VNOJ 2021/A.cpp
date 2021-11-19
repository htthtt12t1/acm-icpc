#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define SET(a,x) memset((a),x,sizeof(a))
#define mod  99824435312111LL
#define base 311LL
#define big 1000000000LL
#define bigg  1000000000LL
#define fi first
#define se second
#define mp make_pair
#define all(a) a.begin(),a.end()
#define getbit(n, i) ((n >> (i)) & 1)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef pair<ii,ii> iiii;

inline ll POW(ll n, ll k, ll p = mod) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}

const int N = 100005;

ll n,so;



ll vtgiua(ll u)
{
    return (u + big/2 - 1) % big;
}
int dem = 0;
void hoi(ll u,ll v)
{
    u = u % big;
    v = v % big;
    dem++;
    cout << "QUERY " << u << " " << v << endl;
    fflush(stdout);
    cin >> so;
//    cout << dem << " "  << "QUERY " << u << " " << v << endl;
    fflush(stdout);
}

int main()
{
    cin >> n;
    ll dau = 0,cuoi = 0;
    hoi(dau,vtgiua(dau));
    ll left,right;
    if(so == n/2)
    {
        cout << "YES " << 0;
        return 0;
    }
    if(so < n/2) left = (vtgiua(dau) + 2) % big;
    else left = dau + 1;
    right = left + big/2 - 2;

    while(left <= right)
    {
        ll mid = (left + right) >> 1;
        if(left < right) hoi(mid,vtgiua(mid));
        if(left == right || so == n/2)
        {
            cout << "YES " << mid % big;
            return 0;

        }
        else if(so > n/2)
        {
            left = mid + 1 ;
        }
        else
            right = mid - 1;
    }



}