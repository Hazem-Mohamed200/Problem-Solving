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
string base3(ll n)
{
    string ans = "";
    while(n)
    {
        ans += (n%3)+'0';
        n/=3;
    }
    reverse(all(ans));
    return ans;
}
ll power(ll x, ll y)
{
    if(y == 0)
        return 1;
    ll xh = x;
    for(int i = 1; i < y; i++)
        x *= xh;
    return x;
}
ll convert(string s)
{
    ll num = 0;
    int j = 0;
    for(int i = s.length()-1; i >= 0; i--)
    {
        num += power(3,j)*(s[i]-'0');
        j++;
    }
    return num;
}
int main()
{
    zuka();
    int q; cin >> q;
    while(q--)
    {
        ll n; cin >> n;
       string s = base3(n);
       string hld =s;
       int stop = s.length();
       for(int i = s.length()-1; i >= 0; i--)
       {
           if(s[i] == '2' && i)
           {
               s[i] = '0';
               if(s[i-1] == '0')
                   s[i-1] = '1';
               else
                   s[i-1] = '2';

               stop = i;
               hld = s;
           }
           else if(s[i] == '2' && i == 0)
           {
               hld = "1";
               s[i] = '0';
               hld += s;
               stop = i+1;
               break;
           }
       }
       for(int i = stop; i < hld.length(); i++)
           hld[i] = '0';
       //reverse(all(s));
       cout << convert(hld) << el;
    }

}