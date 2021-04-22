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
bool dis(ll n)
{
    string ss = to_string(n);
    set<int>vv;
    for(int i = 0; i < ss.length(); i++)
        vv.insert(ss[i]);
    if(vv.size() != ss.length())
        return false;
    return true;
}
ll sum(ll n)
{
    ll su = 0;
    while(n)
    {
        su += n%10;
        n/=10;
    }
    return su;
}
set<pll>s;
void gen()
{
    for(int mask = 0; mask < (1 << 9); mask++)
    {
        ll num = 0;
        ll p = 1;
        for(int bit = 0; bit < 9; bit++)
        {
            if((mask >> bit)&1)
            {
                num = num * p + (bit + 1);
                p = 10;
            }
        }
        if(dis(num) && num)
            s.insert({sum(num),num});
    }
}
int main()
{
    zuka();
    gen();
    //cout << (*--s.end()).S;
    int t; cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        auto it = s.lower_bound({x,0});
        if((*it).F == x)
            cout << (*it).S << el;
        else
            cout << -1 << el;
    }

}