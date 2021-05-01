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
const ll N = 200005; const ll mod = 1000000007;
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
ll s[N];
int main()
{
    //zuka();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vec(ll)r,b,tot;
        ll s1 = 0, s2 = 0;
        ll hld1 = 0, hld2 = 0;
        for(int i = 0; i < n; i++)
        {
            ll in; cin >> in;
            r.pb(in);
            hld1 += in;
            s1 = max(s1,max((ll)0,hld1));
        }
        int m; cin >> m;
        for(int i = 0; i < m; i++)
        {
            ll in; cin >> in;
            b.pb(in);
            hld2 += in;
            s2 = max(s2,max((ll)0,hld2));
        }
        cout << s1+s2 << el;

    }
}

