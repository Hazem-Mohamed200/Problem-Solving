#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define F first
#define S second
#define pb push_back
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "wt", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 2e5+5; const ll mod = 1e9+7;

int n, c;
ll dp[N][2];
ll a[N], b[N];
void solve()
{
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1e9+10, dp[i][1] = 1e9 + 10;

    dp[0][0] = 0;
    dp[0][1] = c;
    for(int i = 1; i < n; i++)
    {
       dp[i][0] = min(dp[i-1][0] + a[i-1], dp[i-1][1] + a[i-1]);
       dp[i][1] = min(dp[i-1][1] + b[i-1], dp[i-1][0] + b[i-1] + c);
    }
    for(int i = 0; i < n; i++)
        cout << min(dp[i][0], dp[i][1]) << ' ';
}
void testCase()
{
    cin >> n >> c;
    for(int i = 0; i < n-1; i++)
        cin >> a[i];

    for(int i = 0; i < n-1; i++)
        cin >> b[i];
    solve();
}
int main()
{
    Zuka
    int t = 1;
    //cin >> t;
    while(t--)
       testCase();
}