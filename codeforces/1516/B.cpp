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
const ll MAX = 100005; const ll mod = 1000000007;
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
        int n; cin >> n;
        vec(ll)v(n);
        ll res = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            res = res ^ v[i];
        }
        if(res == 0)
            cout << "YES\n";
       else
        {
           ll holder = 0;
           vec(ll)vv;
           for(int i = 0; i < n; i++)
           {
               holder ^= v[i];
               if(holder == res)
               {
                   vv.pb(holder);
                   holder = 0;
               }
           }
           if(vv.size() > 1)
           {
               if(holder == 0)
                   cout << "YES\n";
               else
                   cout << "NO\n";
           }
           else
               cout << "NO\n";
        }
    }
}