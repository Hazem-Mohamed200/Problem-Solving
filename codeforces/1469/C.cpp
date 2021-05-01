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
int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
    {
        ll n,k; cin >> n >> k;
        bool can = true;
        ll mn,mx;
        ll ground;
        for(int i = 0; i < n; i++)
        {
            ll in; cin >> in;
            if(i == 0)
            {
                mn = in,mx = in;
                continue;
            }
            mn = max(in,mn-(k-1));
            mx = min(mx+(k-1),in+(k-1));
            //cout << mn << ' ' << mx << el;
            if(mn > mx)
                can = false;
            if(i == n-1)
                ground = in;
        }
        if(ground < mn || ground > mx)
            can = false;
        cout << (can ? "YES\n":"NO\n");
    }
}

