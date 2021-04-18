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
const ll MAX = 100000; const ll mod = 1000000007;
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
    ll p = 1;
    ll x = 0;
    for(int i = s.length()-1; i >= 0; i--)
    {
        x += (s[i]-'0')*p;
        p*=10;
    }
    return x;
}
int main()
{
    zuka();
    ll n; cin >> n;
    bool done = true;
    int SZ = 0;
    if(to_string(n).length()&1)
    {
        int sz = to_string(n).length()+1;
        sz/=2;
        for(int i = 0; i < sz; i++)
            cout << '4';
        for(int i = 0; i < sz; i++)
            cout << '7';
    }
    else
    {
        int sz = to_string(n).length();
        sz/=2;
        string hld = "";
        for(int i = 0; i < sz; i++)
            hld += '7';
        for(int i = 0; i < sz; i++)
            hld += '4';
        if(n > klaby(hld))
            SZ = to_string(n).length()+2;
        else
            SZ = to_string(n).length();

        ll ans = 1e10;
        for(int mask = 0; mask < (1<<SZ); mask++)
        {
            ll num = 0;
            int ctr = 0;
            for(int bit = 0; bit < SZ; bit++)
            {
                if((mask >> bit)&1)
                {
                    ctr++;
                    num = num*10+7;
                }
                else
                {
                    ctr--;
                    num = num*10+4;
                }
            }
            if(ctr == 0 && num >= n)
                ans = min(num,ans);
        }
        cout << ans;
    }
}
