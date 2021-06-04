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
const ll N = 1e5+5; const ll mod = 1e9+7;

int n;
bool vis[105];
pair<int, int>intervals[105];
void dfs(int node)
{
    if(node)
    vis[node] = true;
    for(int i = 1; i <= n; i++)
    {
        if(intervals[i].F < intervals[node].F && intervals[i].S > intervals[node].F)
        {
            if(!vis[i])
                dfs(i);
        }
        else if(intervals[i].F < intervals[node].S && intervals[i].S > intervals[node].S)
        {
            if(!vis[i])
                dfs(i);
        }
    }
}
void testCase()
{
    cin >> n;
    int cnt = 1;
    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        if(t == 1)
        {
            cin >> intervals[cnt].F >> intervals[cnt].S;
            cnt++;
        }
        else
        {
            int a, b; cin >> a >> b;
           memset(vis, false, 105);
           dfs(a);
            if(vis[b])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
int main()
{
    Zuka
    int t = 1;
    //cin >> t;
    while(t--)
        testCase();
}