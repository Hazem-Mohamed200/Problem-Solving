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
const ll mod = 1000000007;
const ll MAX = 1e7+5;
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
ll ans[MAX];
ll d[MAX];
int main()
{
    zuka();
    ll mx = 0;
    for(ll i = 1; i <= MAX; i++)
        for(ll j = i; j <= MAX; j+=i)
            d[j]+=i;

    for(ll i = 1; i <= MAX; i++)
    {
        ll x = d[i];
        if(x <= 1e7 && !ans[x])
            ans[x] = i;
        else if(x <= 1e7 && ans[x])
            ans[x] = min(i,ans[x]);
    }
    int t; cin >> t;
    while(t--)
    {
        int in; cin >> in;
        if(ans[in])
            cout << ans[in] << el;
        else
            cout <<"-1\n";
    }
}
