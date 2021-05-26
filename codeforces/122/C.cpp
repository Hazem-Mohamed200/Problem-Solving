#include <bits/stdc++.h>
using namespace std;
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
#define file freopen("input.txt","r" , stdin),freopen("output.txt" , "w" , stdout);
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int Dx[] = {-1, -1, -1,  0, 0,  1, 1,  1};
int Dy[] = {-1,  0,  1, -1, 1, -1, 0,  1};

const ll N = 2e5+5; const ll mod = 1e9+7;

set<ll>lucky;
void fun(ll x)
{
    if(x >= (ll)1e10)
        return;
    lucky.insert(x);
    fun(x * 10 + 4);
    fun(x * 10 + 7);
}
int main()
{
    Zuka
    fun(0);
    vec(ll)v;
    for(auto i:lucky)
    {
        v.push_back(i);
        if(i >= 1e9)
            break;
    }
    int l,r; cin >> l >> r;
    ll sum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] >= l && v[i] <= r)
        {
            sum += ((v[i] - l + 1) * v[i]);
            l = v[i] + 1;
        }
        else if (v[i] > r)
        {
            sum += ((r - l + 1) * v[i]);
            break;
        }
    }
    cout << sum;
}