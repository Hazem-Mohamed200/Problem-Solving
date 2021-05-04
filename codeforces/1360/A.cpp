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
int dx[8] = {-1, -1, -1,  0, 0,  1, 1,  1};
int dy[8] = {-1,  0,  1, -1, 1, -1, 0,  1};
const ll N = 44; const ll mod = 1000000007;

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
void step(int& a, int& b, int q)
{
    int step = a - b * q;
    a = b;
    b = step;
}
int eGCD(int a, int b, int& x0, int& y0)
{
    int x1,y1,r0,r1;
    r0 = a, r1 = b;
    x0 = y1 = 1;
    x1 = y0 = 0;
    while(r1)
    {
        int q = r0/r1;
        step(x0,x1,q);
        step(y0,y1,q);
        step(r0,r1,q);
    }
    return r0;
}
int modInv(int c, int m)
{
    int x,y;
    int g = eGCD(c,m,x,y);
    if(g != 1)
        return -1;
    return x;
}
ll fsp(int b, int p)
{
    if(p == 1)
        return b;
    ll temp = fsp(b, p / 2);
    if(p%2)
        return temp*temp*b;
    else
        return temp*temp;

}
int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
    {
        ll a,b; cin >> a >> b;
        if(a < b)
            swap(a,b);
        ll a1 = (a*b)*2;
        ll a2 = (a*a);
        ll a3 = (b*2)*(b*2);
        cout << max(a2,a3) << el;
    }
}
