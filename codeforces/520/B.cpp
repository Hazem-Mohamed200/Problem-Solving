#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const ll N = 50005; const ll mod = 1e9+7;
bool vis[N];
int n,m;
void shortestPath(int node, vector<vector<pair<int, int>>>graph)
{
    vector<int>cost(N,1e9);
    cost[node] = 0;
    priority_queue<pair<int, int>>q;
    q.push({0,node});
    while(q.size())
    {
        int from = q.top().second;
        q.pop();
        if(vis[from])
            continue;
        vis[from] = true;
        for(auto e:graph[from])
        {
            int to = e.first;
            int c = e.second;
            if(cost[from] + c < cost[to])
            {
                cost[to] = cost[from] + c;
                q.push({-cost[to],to});
            }
        }
    }
    cout << cost[m];
}
int main()
{
    Zuka
    cin >> n >> m;
    vector<vector<pair<int, int>>>graph(N);
    for(int i = max(n,m)*2; i > 0; i--)
        graph[i].push_back({i-1,1});
    for(int i = 1; i < max(n,m)*2; i++)
        graph[i].push_back({i*2,1});
    shortestPath(n,graph);
}