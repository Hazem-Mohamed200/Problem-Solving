#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const ll N = 1e5+5; const ll mod = 1e9+7;
bool vis[N];
vector<int> ans;
vector<vector<int>>graph(N);
void solve()
{
    priority_queue<int>q;
    q.push(-1);
    vis[1] = true;
    while(q.size())
    {
        int u = q.top();
        q.pop();
        ans.push_back(-u);
        for(auto v:graph[-u])
        {
            if(!vis[v])
            {
                q.push(-v);
                vis[v] = true;
            }
        }
    }
}
int main()
{
    Zuka
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    solve();
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}