#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pff pair<float,float>
#define F first
#define S second
#define vec(int) vector<int>
#define pb push_back
#define pf push_front
#define mms(v,i) memset(v, i, sizeof v)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define file freopen("input.txt","r" , stdin),freopen("output.txt" , "w" , stdout);
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int Dx[] = {-1, -1, -1,  0, 0,  1, 1,  1};
int Dy[] = {-1,  0,  1, -1, 1, -1, 0,  1};


const ll N = 50+5; const ll mod = 1e9+7;

int n,m,k;
bool vis[N][N];
char arr[N][N];
bool valid(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m || arr[i][j] == '*')
        return false;
    return true;
}

void dfs(int i, int j, vector<pair<int,int>>& points, bool& ocean)
{
    if(i == 0 || i == n-1 || j == 0 || j == m-1)
        ocean = false;
    points.pb({i,j});
    vis[i][j] = true;
    for(int koko = 0; koko < 4; koko++)
    {
        int ni = i+dy[koko], nj = j+dx[koko];
        if(valid(ni,nj) && !vis[ni][nj])
        {
            if(ni == 0 || ni == n-1 || nj == 0 || nj == m-1)
            {
                ocean = false;
                dfs(ni, nj, points, ocean);
            }
            else if(ni != 0 && ni != n-1 && nj != 0 && nj != m-1)
            {
                dfs(ni, nj, points, ocean);
            }
        }
    }
}
int main()
{
    Zuka
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    vector< pair<int, vector< pair<int,int> > > >lakes;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == '.' && !vis[i][j] && i != 0 && j != 0 && i != n-1 && j != m-1)
            {
                vector<pair<int,int>>temp;
                bool safe = true;
                dfs(i,j,temp, safe);
                if(temp.size() && safe)
                    lakes.push_back({temp.size(),temp});
            }
        }
    }
    sort(all(lakes));
    int p = 0;
    int cnt = lakes.size();
    int ctr = 0;
    while(cnt != k)
    {
        for(auto i:lakes[p].S)
        {
            arr[i.F][i.S] = '*';
            ctr++;
        }
        cnt--;
        p++;
    }
    cout << ctr << el;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << arr[i][j];
        }
        cout << el;
    }
}