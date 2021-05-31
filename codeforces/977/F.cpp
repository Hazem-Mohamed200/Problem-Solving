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

int n;
int dp[N];
map<int,int>Dp;
int arr[N];
map<int,vector<int>>freq;
map<int,int>freqq;

void solve()
{
    dp[n] = 1;
    Dp[arr[n]] = 1;
    freq[arr[n]].pb(n);
    freqq[arr[n]]++;
    for(int i = n-1; i >= 1; i--)
    {
        bool f = false;
        int key = arr[i] + 1;
        freqq[arr[i]]++;
        Dp[arr[i]] = max(Dp[arr[i]], Dp[key] + 1);
    }
    int mx = 0;
    int key = -1;
    for(auto i:freqq)
    {
        if(Dp[i.first] > mx)
        {
            mx = Dp[i.first], key = i.F;
        }
    }
    cout << mx << el;
    for(int i = 1; i <= n; i++)
    {
       if(arr[i] == key)
           cout << i << ' ', key++;
    }
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