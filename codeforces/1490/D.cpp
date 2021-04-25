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
int n;
int ans[105];
int v[105];
void solve(int l, int r,int depth)
{
    if(l > r)
        return;
    if(r == l)
    {
        ans[r] = depth;
        return;
    }
    int mx = 0,idx = -1;
    for(int i = l; i <= r; i++)
    {
        if(v[i] > mx)
        {
            mx = v[i];
            idx = i;
        }
    }
    ans[idx] = depth;
    solve(l,idx-1,depth + 1); //Left
    solve(idx+1,r,depth + 1); //Right
}
int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
    {
        mms(v,0);
        mms(ans,0);
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> v[i];
        solve(0,n-1,0);
        for(int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << el;
    }
}