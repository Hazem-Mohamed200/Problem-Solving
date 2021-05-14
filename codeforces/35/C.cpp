#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

const ll N = 2005; const ll mod = 1e9+7;

int n, m;
bool vis[N][N];
pair <int, int> last;
vector<pair<int, int>>s;
int dx[] = {0,  0, 1, -1};
int dy[] = {1, -1, 0,  0};
bool valid(int i, int j)
{
    if(i < 1 || i > n || j < 1 || j > m)
        return false;
    else
        return true;
}
void bfs()
{
    queue< pair <int, int> > q;
    for(auto i:s)
        q.push({i.first, i.second});
    while(q.size())
    {
        int i = q.front().first, j = q.front().second;
        q.pop();
        if(vis[i][j])
            continue;
        else
            vis[i][j] = true;
        last = {i,j};
        for(int k = 0; k < 4; k++)
        {
            int ni = i+dy[k], nj = j+dx[k];
            if(valid(ni, nj) && !vis[ni][nj])
                q.push({ni, nj});
        }
    }
}
int main()
{
    file
    int k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        int x,y; cin >> x >> y;
        s.push_back({x,y});
    }
    bfs();
    cout << last.first << ' ' << last.second;
}