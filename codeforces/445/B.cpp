#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const ll N = 55; const ll mod = 1e9+7;
bool vis[N];
void dfs(int node, map<int,vector<int>>graph)
{
    vis[node] = true;
    for(auto child:graph[node])
    {
        if(!vis[child])
            dfs(child,graph);
    }
}
int cntGraphs(int n, map<int,vector<int>>graph)
{
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfs(i,graph);
            res++;
        }
    }
    return res;
}
int main()
{
    Zuka
    int n,m;
    cin >> n >> m;
    map<int,vector<int>>graph;
   for(int i = 0; i < m; i++)
   {
       int u,v; cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
   }
   ll ans = 1LL << n;
   int minus = cntGraphs(n,graph);
   //cout << minus << el;
   while(minus)
   {
       ans/=2;
       minus--;
   }
   cout << ans;
}