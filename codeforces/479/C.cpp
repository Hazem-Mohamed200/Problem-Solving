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
    int n; cin >> n;
    vec(pll)v;
    for(int i = 0; i < n; i++)
    {
        ll a,b; cin >> a >> b;
        v.pb({a,b});
    }
    sort(all(v));
    ll a,b,cur = 0;
    for(int i = 0; i < n; i++)
    {
        a = v[i].F;
        b = v[i].S;
        if(cur <= b)
            cur = b;
        else
            cur = a;
    }
    cout << cur;
}
