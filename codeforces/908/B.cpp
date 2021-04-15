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
const ll MAX = 4; const ll mod = 1000000007;
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
char maze[51][51];
int directions[4]={0,1,2,3};
int n,m,si,sj;
string s;
int ctr = 0;
bool valid(int r,int c)
{
    if(r < 0 || r >= n || c < 0 || c >= m)
        return false;
    return true;
}
void solve(int i = si,int j = sj)
{
    for(int index = 0; index < s.length(); index++)
    {
        if(s[index]-'0' == directions[0])
            i++;
        else if(s[index]-'0' == directions[1])
            i--;
        else if(s[index]-'0' == directions[2])
           j++;
        else if(s[index]-'0' == directions[3])
            j--;

        if(!valid(i,j) || maze[i][j] == '#')
            return;
        if(maze[i][j] == 'E')
        {
            ctr++;
            return;
        }
    }
    return;
}
int main()
{
    zuka();
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if(maze[i][j] == 'S')
            {
                si = i;
                sj = j;
            }
        }
    }
    cin >> s;
    do{
     solve();
    } while(next_permutation(directions,directions+4));
    cout << ctr;
}