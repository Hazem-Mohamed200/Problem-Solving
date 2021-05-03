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
int dx[8]= {-1, -1, -1,  0, 0,  1, 1,  1};
int dy[8]= {-1,  0,  1, -1, 1, -1, 0,  1};
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
    int next = a - (b*q); // next dah el rem ely 3alih el dor
    // shifting
    a = b;
    b = next;
}
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
int eGCD(int a, int b, int& x0, int& y0)
{
    // x,y holders  rems
    int x1, y1, r0 = a, r1 = b;
    x0 = y1 = 1;
    x1 = y0 = 0;
    while(r1 != 0)
    {
            // Ri-2/Ri-1
        int q = r0/r1;
        step(x0,x1,q);
        step(y0,y1,q);
        step(r0,r1,q);
    }
    return r0;
}
string solve()
{
    int n,x; cin >> n >> x;
    vec(int)v;
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        int in; cin >> in;
        v.pb(in);
        s += in;
    }
    if(s == x)
        return "NO\n";
    s = 0;
    for(int i = 0; i < n; i++)
    {
        s += v[i];
        if(s == x)
        {
           swap(v[i],v[i+1]);
           break;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++)
        cout << v[i] << ' ';
    return "\n";
}
int main()
{
   int t; cin >> t;
   while(t--)
       cout << solve();

}
