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
        ll a,b,x,y,n;
        cin >> a >> b >> x >> y >> n;
        ll ans = 1e18;
        ll diff1 = min(n,a-x);
        ll diff2 = min(n-diff1,b-y);
        ans  = min(ans,(a-diff1)*(b-diff2));
        diff1 = min(n,b-y);
        diff2 = min(n-diff1,a-x);
        ans = min(ans,(a-diff2)*(b-diff1));
        cout << ans << el;
    }
}