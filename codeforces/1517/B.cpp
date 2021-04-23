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
const ll MAX = 500100; const ll mod = 1000000007;
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
    int t; cin >> t;
    while(t--)
    {
        int n,m; cin >> n >> m;
        // n+1 checkpoints 0 ----> n
        ll ans[101][101]={};
        multiset<pll>ms;
        vector<multiset<ll>>v(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ll in; cin >> in;
                ms.insert({in,i});
                v[i].insert(-in);
            }
        }
        int point = 0;
        for(auto x:ms)
        {
            ll num = x.F;
            int i = x.S;
            ans[i][point] = num;
            v[i].erase(v[i].find(-num));
            point++;
            if(point == m)
                break;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!ans[i][j])
                {
                    ans[i][j] = -(*v[i].begin());
                    v[i].erase(v[i].begin());
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout << ans[i][j] << ' ';
            }
            cout << el;
        }
    }

}