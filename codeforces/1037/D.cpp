#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const ll N = 2e5+5; const ll mod = 1e9+7;

int n;
int p = 0;
bool vis[N];
vector<int>seq;
bool can = true;
vector< set<int> >graph(N);
void bfs(int node = 1)
{
    queue<int>q;
    q.push(1);
    if(seq[p] == 1)
        p++;
    else
        can = false;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        set<int>temp;
        for(auto child:graph[u])
        {
            if(!vis[child])
                temp.insert(child);
        }
        while(temp.size())
        {
            int sz = temp.size();
            auto it = temp.find(seq[p]);
            if(it != temp.end())
            {
                q.push(seq[p++]);
                temp.erase(it);
            }
            else
            {
                can = false;
                break;
            }
        }
    }
}
int main()
{
    Zuka
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int u,v; cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    for(int i = 0; i < n; i++)
    {
        int in; cin >> in;
        seq.push_back(in);
    }
    bfs(1);
    cout << (can ? "YES":"NO");
}