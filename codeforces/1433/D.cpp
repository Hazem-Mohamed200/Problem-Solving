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
        int n; cin >> n;
        set<int>s;
        vec(int)v;
        vec(pii)ans;
        for(int i = 0; i < n; i++)
        {
            int in; cin >> in;
            s.insert(in);
            v.pb(in);
        }
        if(s.size() == 1)
        {
            cout << "NO\n";
            continue;
        }
        // kolo m3 awl wa7da ma 3da ely zyha w5las
        int mkan_awl_wa7da_diff = 0;
        for(int i = 1; i < n; i++)
        {
            if(v[i] == v[0])
                continue;
            else
            {
                if(!mkan_awl_wa7da_diff)
                    mkan_awl_wa7da_diff = i+1;
                ans.pb({1,i+1});
            }
        }
        for(int i = 1; i < n; i++)
        {
            if(v[i] != v[0])
                continue;
            else
            {
                ans.pb({mkan_awl_wa7da_diff,i+1});
            }
        }
        cout << "YES\n";
        for(auto i:ans)
            cout << i.F << ' ' << i.S << el;
    }
}