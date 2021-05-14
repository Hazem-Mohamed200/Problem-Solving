#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 1e5+5; const ll mod = 1e9+7;

int n,m;
bool vis[N];
map< pair<int,int>,bool > times;
vector< pair<int,int> >graph[N];
void dijkstra()
{
    vector< ll >cost(N,INF);
    priority_queue< pair<ll, ll> >q;
    q.push({0,1});
    while(q.size())
    {
        int u = q.top().second, c = -q.top().first;
        q.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        while(times[{u,c}])
            c++;
        for(auto i : graph[u])
        {
            int cc = i.second, v = i.first;
            ll tc = c+cc;
            if(tc < cost[v])
            {
                cost[v] = tc;
                q.push({-tc,v});
            }
        }
    }
    if(cost[n] == INF)
        cout << -1;
    else
        cout << cost[n];
}
int main()
{
    Zuka
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        graph[u].push_back({v,c});
        graph[v].push_back({u,c});
    }
    for(int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        for(int j = 0; j < k; j++)
        {
            int t; cin >> t;
            times[{i,t}] = true;
        }
    }
    dijkstra();
}