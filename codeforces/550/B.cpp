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
const ll MAX = 1000006; const ll mod = 1000000007;
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
    int n;
    ll l,r,x;
    cin >> n >> l >> r >> x;
    vec(ll)v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int ans = 0;
    for(int msk = 0; msk < (1 << n); msk++)
    {
        ll mx = 0;
        ll mn = 1e18;
        ll sum = 0;
        for(int bit = 0; bit < n; bit++)
        {
            if((msk >> bit)&1)
            {
                mx = max(mx,v[bit]);
                mn = min(mn,v[bit]);
                sum += v[bit];
            }
        }
        if(sum >= l && sum <= r && mx-mn >= x)
            ans++;
    }
    cout << ans;
}