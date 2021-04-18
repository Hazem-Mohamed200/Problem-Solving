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

int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
    {
        ll a,b;
        cin >> a >> b;
        ll dif = abs(a-b);
        int ans = 0;
        ll hld = 0;
        if(a == b)
            cout << 0 << el;
        else
        {
            for(int i = 10; i >= 1; i--)
            {
                ans += dif/i;
                dif -= i*(dif/i);
                if(dif < 0)
                {
                    dif += i*(dif/i);
                    ans -= dif/i;
                }
            }
            cout << ans << el;
        }
    }
}