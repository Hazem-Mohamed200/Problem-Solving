#include <bits/stdc++.h>
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
int dx[]= {0, 1, 0, -1};
int dy[]= {1, 0, -1, 0};
const ll MAX = 1000006; const ll mod = 1000000007;
using namespace std;

void file()
{
    freopen("input.txt","r" , stdin);
    freopen("output.txt" , "w" , stdout);
}
void zuka()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int grid[9][9];
bool checkBox(int x, int y, int num)
{
    int freq[9]={0};
    if(x <= 4)
    {
        if(y <= 4)
        {
            for(int i = 1; i <= 4; i++)
            {
                for(int j = 1; j <= 4; j++)
                {
                    if(i == x && j == y)
                        freq[num]++;
                    else
                    freq[grid[i][j]]++;
                }
            }
        }
        else
        {
            for(int i = 1; i <= 4; i++)
            {
                for(int j = 5; j <= 8; j++)
                {
                    if(i == x && j == y)
                        freq[num]++;
                    else
                        freq[grid[i][j]]++;
                }
            }
        }
    }
    else
    {
        if(y <= 4)
        {
            for(int i = 5; i <= 8; i++)
            {
                for(int j = 1; j <= 4; j++)
                {
                    if(i == x && j == y)
                        freq[num]++;
                    else
                        freq[grid[i][j]]++;
                }
            }
        }
        else
        {
            for(int i = 5; i <= 8; i++)
            {
                for(int j = 5; j <= 8; j++)
                {
                    if(i == x && j == y)
                        freq[num]++;
                    else
                        freq[grid[i][j]]++;
                }
            }
        }
    }

    for(int i = 1; i <= 8; i++)
        if(freq[i] >= 3)
            return false;
    return true;
}
bool checkRow(int x, int y, int num)
{
    for(int i = 1; i <= 8; i++)
    {
        if(i == y)
            continue;
        if(grid[x][i] == num)
            return false;
    }
    return true;
}
bool checkCol(int x, int y, int num)
{
    for(int i = 1; i <= 8; i++)
    {
        if(i == x)
            continue;
        if(grid[i][y] == num)
            return false;
    }
    return true;
}
bool Safe(int x, int y, int num)
{
    if(checkRow(x, y, num) && checkCol(x, y, num) && checkBox(x, y, num))
        return true;
    return false;
}
bool checkGrid()
{
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
            if(!Safe(i, j, grid[i][j]))
                return false;
    }
    return true;
}
bool preCheck()
{
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
            if(grid[i][j] && !Safe(i, j, grid[i][j]))
                return false;
    }
    return true;
}
int countZero(int arr[9][9])
{
    int cc = 0;
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            if(!arr[i][j])
                cc++;
        }
    }
    return cc;
}
bool Solve(int row, int col)
{
    // Base Case
    if(col == 9)
    {
        row++;
        col = 1;
        if(row == 9)
            return checkGrid();
    }

    if(grid[row][col])//m4 zero ya3ny malo4 lazma n4ofo
        return Solve(row, col + 1);

    for(int i = 1; i <= 8; i++)
    {
        if(Safe(row, col, i))
        {
            grid[row][col] = i;
            if(Solve(row, col + 1))
                return true;
        }
        if(countZero(grid) != 0)
            grid[row][col] = 0;
    }
    return true;
}
ll n;
int ctr = 0;
void solve(ll num = 1)
{
    if(num > n)
        return;
    if(num <= n)
        ctr++;
    solve(num*10+1);
    solve(num*10);
}
int main()
{
    zuka();
    cin >> n;
    solve();
    cout << ctr;
}