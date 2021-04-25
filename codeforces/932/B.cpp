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
ll arr[10][MAX];
ll f(ll x)
{
    string s = to_string(x);
    ll product = 1;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i]-'0' != 0)
            product*=(s[i]-'0');
    }
    return product;
}
ll g(ll x)
{
    if(x < 10)
        return x;
    else
        g(f(x));
}
void solve(int index)
{
    if(index > MAX)
        return;
    ll x = g(index);
    for(int i = 1; i <= 9; i++)
    {
        if(i == x)
            arr[i][index] = arr[i][index-1]+1;
        else
            arr[i][index] = arr[i][index-1];
    }
    solve(index + 1);
}
int main()
{
    zuka();
    //solve(1);
    for(int i = 1; i < MAX; i++)
    {
        ll x = g(i);
        for(int j = 1; j <= 9; j++)
        {
            if (j == x)
                arr[j][i] = arr[j][i - 1] + 1;
            else
                arr[j][i] = arr[j][i - 1];
        }
    }
    int q; cin >> q;
    while(q--)
    {
        int l,r,k; cin >> l >> r >> k;
        cout << arr[k][r]-arr[k][l-1] << el;
    }
}