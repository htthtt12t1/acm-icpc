#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define SET(a,x) memset((a),x,sizeof(a))
#define mod  99824435312111LL
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

const int N = 100005;

int n,xx,yy,r,c,dem = 0;
int dd[105][105];
deque<ii> g;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main()
{
    if (fopen("text.inp","r"))
    {
       freopen("text.inp","r",stdin);
       freopen("text.out","w",stdout);
    }
    int t;
    cin >> r >> c >> n;
    int dem = 0;
    FOR(i,1,n)
    {
        cin >> xx >> yy;
        if(dd[xx][yy] == 0) dem++,g.push_back(mp(xx,yy));
        dd[xx][yy] = 1;
    }
    int res = 1;
    while(dem != r * c)
    {
        res++;
        int cuoi = g.size() - 1;
        FOR(h,0,cuoi)
        {
            int u = g[0].fi;
            int v = g[0].se;
            FOR(i,0,3)
                FOR(j,0,3)
                {
                    int x = u + dx[i], y = v + dy[i];
                    if(x >= 1 && y >= 1 && x <= r && y <= c && dd[x][y] == 0)
                    {
                        g.push_back(mp(x,y));
                        dd[x][y] = 1;
                        dem++;
                    }
                }
            g.pop_front();
        }
    }
    cout << res;
}