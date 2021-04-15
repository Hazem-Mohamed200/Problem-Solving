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
const ll MAX = 4; const ll mod = 1000000007;
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
ll n;
ll count(string s,char x)
{
    int ctr = 0;
    for(auto i:s)
        if(i == x)
            ctr++;
    return ctr;
}
ll klaby(string s)
{
    ll num = 0;
    ll p = 1;
    for(int i = s.length()-1; i >= 0; i--)
    {
       int nn = s[i]-'0';
       num += nn*p;
       p*=10;
    }
    return num;
}
set<ll>v;
void fun(ll lucky)
{
    if(lucky > 1e10)
        return;
    else if(count(to_string(lucky),'4') == count(to_string(lucky),'7'))
         v.insert(lucky);

    fun(lucky * 10 + 4);
    fun(lucky * 10 + 7);
}
int main()
{
    zuka();
    cin >> n;
    fun(0);
   cout << *v.lower_bound(n);
}