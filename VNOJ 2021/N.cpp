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

ll n;
ll x[N],y[N];

void write(int u,int v,int x,int y)
{
    cout << "?" << " " << u << " " << v << " " << x << " " << y << endl;

}

int main()
{
    int t;
    ios_base::sync_with_stdio(false);
    int u = 1, v = 1, x = big,y = big;
    write(u,v,x,y);
    ll s;
    cin >> s;
    ll xx,yy;
    int left = 1, right = x;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        write(u,v,mid,y);
        cin >> xx;
        if(xx == s) x = mid,right = mid - 1;
        else left = mid + 1;
    }

    left = 1, right = y;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        write(u,v,x,mid);
        cin >> yy;
        if(yy == s) y = mid,right = mid - 1;
        else left = mid + 1;
    }
    write(x,v,x,y);
    ll tam;
    cin >> tam;
    v = y - tam + 1;
    u = x - s / tam + 1;
    cout << "! " << u << " " << v << " " << x << " " << y;


}
