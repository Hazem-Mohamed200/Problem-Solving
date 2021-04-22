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
const ll MAX = 500100; const ll mod = 1000000007;
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
vec(ll)arr(MAX);
vec(ll)hld(MAX);
ll prefix[MAX];
ll kh,n,r,lim;
bool check(ll mid)
{
    ll sum = 0;
    queue<pll>q;
    hld = arr;
    for(int i = 0; i < n; i++)
    {
        while(q.size() && q.front().S < i)
        {
            sum -= q.front().F;
            q.pop();
        }
        hld[i] = max((ll)0,hld[i] + sum);
        ll x = max((ll)0,mid - hld[i]);
        if(x)
        {
            q.push({x,i+2*r});
            kh -= x;
            if(kh < 0)
                return false;
            sum += x;
        }
    }
    return 1;
}
int main()
{
    zuka();
    ll k;
    cin >> n >> r >> k;
    vec(ll)v;
    for(int i = 0; i < n; i++)
    {
        ll in; cin >> in;
        v.pb(in);
        if(i == 0)
            prefix[i] = v[i];
        else
            prefix[i] = prefix[i - 1] + v[i];
    }
    ll mn = 2.1e18;
    ll mx = 0;
    for(int i = 0; i < n; i++)
    {
        if(i+r < n)
            arr[i] = prefix[i + r];
        else
            arr[i] = prefix[n-1];
        if(i > r)
            arr[i] -= prefix[i-r-1];
        mn = min(mn,arr[i]);
        mx = max(mx,arr[i]);
    }
//    for(auto i = 0; i < n; i++)
//        cout << arr[i] << ' ';
    ll s = mn,e = mx+k,mid,res = mn;
    while(s <= e)
    {
        mid = (s+e) >> 1;
        // mid is the required minimum defence level
        kh = k;
        if(check(mid))
        {
            res = max(res,mid);
            s = mid+1;
        }
        else
            e = mid-1;
    }
    cout << res;
}