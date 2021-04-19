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
const ll MAX = 1000005; const ll mod = 1000000007;
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
int l[MAX],r[MAX];
int main()
{
    zuka();
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(j == m)
            break;
        if(s[i] == t[j])
        {
            l[j] = i;
            j++;
        }
    }
    j = m-1;
    for(int i = n-1; i >= 0; i--)
    {
        if(j == -1)
            break;
        if(s[i] == t[j])
        {
            r[j] = i;
            j--;
        }
    }
    int ans = 0;
    for(int i = 1; i < m; i++)
        ans = max(ans,r[i]-l[i-1]);
    cout << ans;
}