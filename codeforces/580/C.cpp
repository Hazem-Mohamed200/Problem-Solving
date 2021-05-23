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

int mxCats;
bool cats[N];
bool vis[N];
bool canGo[N];
set<int>leafs;
vector<int>graph[N];
void bfs()
{
    queue<pair<int,int>> q;
    q.push({1, cats[1]});
    while(q.size())
    {
        int u = q.front().first;
        int holder = q.front().second;
        canGo[u] = true;
        q.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        for(auto v : graph[u])
        {
            if(cats[v])
            {
                if(cats[v] + holder <= mxCats)
                {
                    q.push({v, holder+1});
                }
            }
            else
                q.push({v, 0});
        }
    }
    memset(vis, false, sizeof vis);
}
void getLeafs(int node = 1)
{
    vis[node] = true;
    bool leaf = true;
    for(auto v:graph[node])
    {
        if(!vis[v])
        {
            leaf = false;
            getLeafs(v);
        }
    }
    if(leaf)
        leafs.insert(node);
}
int main()
{
    Zuka
    int n;
    cin >> n >> mxCats;
    for(int i = 1; i <= n; i++)
        cin >> cats[i];
    for(int i = 0; i < n-1; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs();
    getLeafs();
    int ans = 0;
    for(auto i:leafs)
        if(canGo[i])
            ans++;
    cout << ans;
}
// Hazem Mohamed