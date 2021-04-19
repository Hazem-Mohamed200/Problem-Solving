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
const ll MAX = 1000005; const ll mod = 1000000007;
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
ll klaby(string s)
{
    ll x = 0,p = 1;
    for(int i = s.length()-1; i >= 0; i--)
    {
        x += (s[i]-'0')*p;
        p*=10;
    }
    return x;
}
ll power(ll x , ll y)
{
    if (y == 0)
        return 1;
    ll xh = x;
    for (int i = 1; i < y; i++)
        x = ((xh%mod)*(x%mod))%mod;
    return x;
}
int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
    {
        int n,k; cin >> n >> k;
        cout << power(n,k)%mod << el;
    }
}