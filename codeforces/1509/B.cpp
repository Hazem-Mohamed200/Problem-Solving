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

int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int c1 = 0,c2 = 0;
        set<int>ts,tsh;
        map<int,bool>mp;
        bool fail = false;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'M')
            {
                if(tsh.size())
                    tsh.erase(--tsh.end());
                else
                {
                    fail = true;
                    break;
                }
                c1++;
            }
            else
            {
                ts.insert(i);
                tsh.insert(i);
                c2++;
            }

        }
        if(c2/2 != c1||fail)
        {
            cout << "NO\n";
            continue;
        }
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'M')
            {
                if(*ts.begin() < i)
                {
                    ts.erase(ts.begin());
                    auto it = ts.lower_bound(i);
                    if(it != ts.end())
                        ts.erase(it);
                    else
                    {
                        fail = true;
                        break;
                    }
                }
            }
        }
        if(fail)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}