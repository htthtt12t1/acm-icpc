#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define SET(a,x) memset((a),x,sizeof(a))
#define mod  1000000007LL
#define base 311LL
#define big  1000000000
//#define big  1000
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

const int N = 1000005;

ll n,u,m;
int f[N];
int a[N];

int main()
{
    if (fopen("text.inp","r"))
    {
       freopen("text.inp","r",stdin);
       freopen("text.out","w",stdout);
    }
    int t;
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n >> u >> m;
        FOR(i,1,n) cin >> a[i];
        int sum = 0;
        ll res = INT_MAX;
        FOR(i,1,n) sum += a[i];
        FOR(i,1,sum) f[i] = 0;
        if(n * sum <= 1000000)
        {

            f[0] = 1;
            FOR(i,1,n)
                FORD(j,sum,a[i]) if(f[j - a[i]]) f[j] = 1;
            FOR(i,0,sum) if(f[i] == 1) res = min(res,max((i+u-1)/u,(sum-i+m-1)/m));
            cout << res << endl;
        }
        else
        {
            cout << (sum + (u+m-1) ) /(u+m) << endl;
        }

    }


}

