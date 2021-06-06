#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define F first
#define S second
#define pb push_back
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "wt", stdout);

//const ll INF = LONG_LONG_MAX;
const ll N = 1e5+5; const ll mod = 1e9+7;

int n;
ll dp[N];
ll freq[N];
int arr[N];
void solve()
{
    dp[0] = 0;
    dp[1] = freq[1];
    for(int i = 2; i <= (int)1e5; i++)
    {
        dp[i] = max(((freq[i]*i) + dp[i-2]), dp[i-1]);
    }
    cout << dp[(int)1e5];
}
void testCase()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i], freq[arr[i]]++;
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