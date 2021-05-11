#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const ll N = 105; const ll mod = 1e9+7;

int n,m;
bool vis[N];
vector< vector<int> >langs(N),graph(N);
void dfs(int node)
{
    vis[node] = true;
    for(int i = 0; i < graph[node].size(); i++)
    {
        for(int j = 0; j < langs[graph[node][i]].size(); j++)
        {
            if(!vis[langs[graph[node][i]][j]])
                dfs(langs[graph[node][i]][j]);
        }
    }
}
int main()
{
    Zuka
    cin >> n >> m;
    map<int, int>freq;
    for(int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        while(k--)
        {
            int lang; cin >> lang;
            langs[lang].push_back(i);
            graph[i].push_back(lang);
            freq[lang]++;
        }
    }
    int mx = 0;
    int ml = 1;
    for(auto i:freq)
    {
        if(i.second > mx)
        {
            mx = i.second;
            ml = i.first;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            if(i == 1)
            {
                if(graph[i].size() == 0)
                {
                    ans++;
                    graph[i].push_back(ml);
                    langs[ml].push_back(i);
                }
            }
            else
                ans++;
            dfs(i);
        }
    }
    cout << ans;
}