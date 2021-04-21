#include <bits/stdc++.h>
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
int dx[]= {0, 1, 0, -1};
int dy[]= {1, 0, -1, 0};
const ll MAX = 100005; const ll mod = 1000000007;
using namespace std;

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
ll gcdsum(ll x)
{
    ll sum = 0;
    ll xh = x;
    while(xh)
    {
        sum += xh%10;
        xh/=10;
    }
    return __gcd(x,sum);
}
int main()
{
    zuka();
   int t; cin >> t;
   while(t--)
   {
       ll n; cin >> n;
      if(gcdsum(n) > 1)
          cout << n << el;
      else
      {
          if(gcdsum(n+1) > 1)
              cout << n+1 << el;
          else
              cout << n+2 << el;
      }
   }
}