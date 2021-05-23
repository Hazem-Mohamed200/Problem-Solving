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
const ll N = 1e5 + 5; const ll mod = 1e9+7;

vector<ll>graph[N];
vector<ll>cost(N);
bool vis[N];
ll temp = INF;
void dfs(int node)
{
    vis[node] = true;
    for(auto i:graph[node])
    {
        if(!vis[i])
        {
            temp = min(temp, cost[i]);
            dfs(i);
        }
    }
}
int main()
{
    Zuka
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        ll in; cin >> in;
        cost[i] = in;
    }
    for(int i = 0; i < m; i++)
    {
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            temp = cost[i];
            dfs(i);
            sum += temp;
        }
    }
    cout << sum;

}