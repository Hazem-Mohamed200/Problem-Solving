#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define F first
#define S second
#define pb push_back
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 1e5+5; const ll mod = 1e9+7;

int n;
ll a[N], b[N];
ll dp[N][3];
void solve()
{
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i-1][1]+a[i], dp[i-1][2]+a[i]);
        dp[i][1] = max(dp[i-1][0]+b[i], dp[i-1][2]+b[i]);
        dp[i][2] = max(dp[i][0]-a[i], dp[i][1]-b[i]);
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
}
int main()
{
    Zuka
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    solve();
}