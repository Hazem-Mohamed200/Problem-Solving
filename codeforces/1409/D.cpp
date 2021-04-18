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
ll sum(ll n)
{
    ll s = 0;
    while(n)
    {
        s+=n%10;
        n/=10;
    }
    return s;
}
int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
    {
        ll n,s; cin >> n >> s;
        if(sum(n) <= s)
        {
            cout << 0 << el;
            continue;
        }
        ll p = 1;
        ll ans = 0;
        for(int i = 1; i <= 18; i++)
        {
            int num = (n/p)%10;// awl digit b3d kda tany digit ans so on...
            ll add = p*(10-num);//m7tag azwd kam 34an asfr el digit dah
            n += add;
            ans += add;
            if(sum(n) <= s)
                break;
            p*=10;
        }
        cout << ans << el;
    }
}