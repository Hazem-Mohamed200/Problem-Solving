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

int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
    {
        int n,c; cin >> n >> c;
        vec(ll)a(n),b(n-1);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n-1; i++)
            cin >> b[i];
        ll res = 1e10;
        ll days = 0,hld = 0,money = 0;
        for(int i = 0; i < n; i++)
        {
            res = min(res,hld+(c-money+a[i]-1)/a[i]);
            if(i < n-1) // lw fy courses
            {
                if(money >= b[i])
                {
                    money -= b[i]; // flos el course
                    hld++; // el youm bta3 el course
                }
                else // law m4 m3aya flos el course b2a
                {
                    days = (b[i]-money+a[i]-1)/a[i];
                    // zwd el flos b2a
                    money += days*a[i]-b[i]; // 4yl flos el course
                    hld = hld + 1 + days; // el youm bta3 el course wel ayam el 7w4t fyha
                }
            }
        }
        cout << res << el;
    }
}