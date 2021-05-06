#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pff pair<float,float>
#define F first
#define S second
#define vec(int) vector<int>
#define pb push_back
#define pf push_front
#define mms(v,i) memset(v, i, sizeof v)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
int dx[8] = {-1, -1, -1,  0, 0,  1, 1,  1};
int dy[8] = {-1,  0,  1, -1, 1, -1, 0,  1};
const ll N = 2e5+5; const ll mod = 1e9+7;

void file()
{
    freopen("input.txt","r" , stdin);
    freopen("output.txt" , "w" , stdout);
}
void zuka()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void step(int& a, int& b, int q)
{
    int step = a - b * q;
    a = b;
    b = step;
}
int eGCD(int a, int b, int& x0, int& y0)
{
    int x1,y1,r0,r1;
    r0 = a, r1 = b;
    x0 = y1 = 1;
    x1 = y0 = 0;
    while(r1)
    {
        int q = r0/r1;
        step(x0,x1,q);
        step(y0,y1,q);
        step(r0,r1,q);
    }
    return r0;
}
int modINV(int c, int m)
{
    int x,y;
    int g = eGCD(c,m,x,y);
    // Handle negative case
    int inv = (x % m + m) % m;
    return (g == 1 ? inv : -1);
}
ll fsp(int b, int p)
{
    if(p == 1)
        return b;
    if(p == 0)
        return 1;
    ll temp = fsp(b, p / 2);
    if(p%2)
        return temp*temp*b;
    else
        return temp*temp;

}
ll fact[N];
ll nCr(int n, int r)
{
    // fact(n) * inv(fact(n-r) * fact(r))
    ll hld = ((fact[n-r]%mod)*(fact[r]%mod))%mod;
    ll koko = modINV(hld,mod);
    return ((fact[n]%mod)*(koko%mod))%mod;
}
int main()
{
    zuka();
    fact[0] = 1;
    ll hld = 1;
    for(ll i = 1; i <= N-5; i++)
    {
        hld = ((hld%mod)*(i%mod))%mod;
        fact[i] = hld;
    }
    int n; cin >> n;
    ll res = (2*nCr(n + (n - 1),n - 1) - n) % mod;
    if(res < 0)
        res += mod;
    cout << res;
}
