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

ll dp[N];
ll arr[N];
ll n, p, k;
ll prefix[N];
void testCase()
{
    memset(dp, 0, sizeof dp);
    memset(prefix, 0, sizeof prefix);

    cin >> n >> p >> k;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    sort(arr, arr + n+1);

    int cnt = 0;
   for(int i = 1; i <= n; i++)
   {
       if(i < k)
           prefix[i] = prefix[i-1] + arr[i];
       else
           prefix[i] = prefix[i-k]+arr[i];
   }

   for(int i = 1; i <= n; i++)
   {
       ll cost = 0;
       // 3nd kol item ha2ol h48l 3ndo el offer
       cost = prefix[i];
       if (cost <= p)
       {
           dp[i] = i;
       }
       else if(i >= k)
       {
           cost = arr[i] + prefix[i - k];
           if (cost <= p)
           {
               dp[i] = max(max(dp[i - 1], dp[i]), (ll) i);
           }
           else
               dp[i] = max(dp[i - 1], dp[i]);
       }
       else
           dp[i] = max(dp[i-1], dp[i]);
   }
   cout << dp[n] << el;

}
int main()
{
    Zuka
    int t = 1;
    cin >> t;
    while(t--)
       testCase();
}