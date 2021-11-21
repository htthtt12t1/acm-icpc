#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define SET(a,x) memset((a),x,sizeof(a))
#define mod  1000000007LL
#define base 311LL
#define big  1000000
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

ll n;
ll x[N],y[N];

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
        cin >> n;
        vector<int> res;
        FOR(i,1,1000000)
        {
            if(i *(i+1) >= n) break;
            if(n%i == 0 && n % (i + 1) == 0) res.push_back(i);
        }
        ll tam = sqrt(n);
        if(tam * (tam+1) == n) res.push_back(tam);
        if(res.size() == 0) cout << -1 << endl;
        else
        {
            FOR(i,0,(int)res.size() - 1) cout << res[i] << " ";
            cout << endl;
        }
    }

}
