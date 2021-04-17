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
const ll MAX = 4; const ll mod = 1000000007;
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
ll power(ll x, ll y)
{
    ll xh = x;
    if(y == 0)
        return 1;
    for(int i = 1; i < y; i++)
        x*=xh;
    return x;
}
int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
    {
        ll n,w; cin >> n >> w;
        ll ans = 1,hld = 0;
        multiset<ll>ms;
        for(int i = 0; i < n; i++)
        {
            int in; cin >> in;
            ms.insert(in);
        }
        while(ms.size())
        {
            auto it = ms.end();
           for(int i = 0; i <= 27; i++)
           {
               auto ith = ms.find(power(2,i));
               if(ith != ms.end() && w-hld >= *ith)
                   it = ith;
           }
           if(it != ms.end())
           {
               hld += *it;
               ms.erase(it);
           }
           else
           {
               ans++;
               hld = 0;
           }
        }
        cout << ans << el;
    }

}