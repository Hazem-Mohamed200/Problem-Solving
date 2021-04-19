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
const ll MAX = 100005; const ll mod = 1000000007;
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
int main()
{
    zuka();
    int arr[30][30]={};
    int n,m; cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for(int j = 0; j < m; j++)
            arr[i][j] = s[j]-'0';
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int hld = 0;
            int tot = 0;
            int stop = -1;
            int rs = i,re = -1,cs = j,ce = 0;
            if(arr[i][j] == 0)
            {
                for(int x = j; x < m; x++)
                {
                    if(arr[i][x] == 0)
                        hld++;
                    else
                    {
                        stop = x-1;
                        break;
                    }
                }
                if(stop == -1)
                    stop = m-1;
                ce = stop;
                tot = hld;
                hld = 0;
                bool fail = false;
                for(int y = i+1; y < n; y++)
                {
                    for(int x = j; x <= stop; x++)
                    {
                        if(arr[y][x] == 0)
                            hld++;
                        else
                        {
                            fail = 1;
                            break;
                        }
                    }
                    if(fail)
                    {
                        re = y-1;
                        break;
                    }
                    else
                    {
                        tot+= hld;
                        hld = 0;
                    }
                }
                if(re == -1)
                    re = n-1;
                int koko = ((re-rs+1)*2)+((ce-cs+1)*2);
                ans = max(ans,koko);
            }
        }
    }
    cout << ans;
}