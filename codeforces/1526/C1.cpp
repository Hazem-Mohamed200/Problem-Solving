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
const ll N = 2000+5; const ll mod = 1e9+7;

int n;
ll arr[N];
ll dp[N][N];
void solve()
{
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(!i || !j)
            {
                dp[i][j] = 0;
                continue;
            }
            else
            {
                if(dp[i-1][j-1] + arr[i] >= 0 && dp[i-1][j-1] >= 0)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + arr[i]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++)
        if(dp[n][i] != -1)
            ans = i;
    cout << ans;
}
void testCase()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
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