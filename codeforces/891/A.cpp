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
const ll N = 1e6+5; const ll mod = 1073741824;

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
void step(ll& a, ll& b, ll q)
{
    ll step = a - b * q;
    a = b;
    b = step;
}
ll eGCD(ll a, ll b, ll& x0, ll& y0)
{
    ll x1,y1,r0,r1;
    r0 = a, r1 = b;
    x0 = y1 = 1;
    x1 = y0 = 0;
    while(r1)
    {
        ll q = r0/r1;
        step(x0,x1,q);
        step(y0,y1,q);
        step(r0,r1,q);
    }
    return r0;
}
int modINV(ll c, ll m)
{
    ll x,y;
    ll g = eGCD(c,m,x,y);
    // Handle negative case
    ll inv = (x % m + m) % m;
    return (g == 1 ? inv : -1);
}
ll fsp(ll b, ll p)
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

//ll nCr(int n, int r)
//{
//    // fact(n) * inv(fact(n-r) * fact(r))
//    ll hld = ((fact[n-r]%mod)*(fact[r]%mod))%mod;
//    ll koko = modINV(hld,mod);
//    return ((fact[n]%mod)*(koko%mod))%mod;
//}

int main()
{
    zuka();
    int n; cin >> n;
    vec(int)v(n);
    int ones = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(v[i] == 1)
            ones++;
    }
    if(ones)
        cout << n-ones;
    else
    {
        int ans = 1e9;
        for(int i = 0; i < n; i++)
        {
            int g = v[i];
            int hld = -1;
            for(int j = i+1; j < n; j++)
            {
               g = __gcd(g,v[j]);
               if(g == 1)
               {
                   hld = j-i;
                   break;
               }
            }
            if(hld != -1)
            ans = min(ans,hld);
        }
       if(ans != 1e9)
           cout << n+ans-1;
       else
           cout << -1;
    }

}
