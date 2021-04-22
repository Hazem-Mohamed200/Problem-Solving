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

void solve()
{
    vec(int)q,mn,mx;
    int n; cin >> n;
    set<int>vault_mn,vault_mx;
    for(int i = 0; i < n; i++)
    {
        int in; cin >> in;
        q.pb(in);
        vault_mn.insert(i + 1);
        vault_mx.insert(i + 1);
    }
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            mn.pb(q[i]);
            mx.pb(q[i]);
            vault_mn.erase(q[i]);
            vault_mx.erase(q[i]);
        }
        else
        {
            if(q[i-1] == q[i])
            {
                mn.pb(*vault_mn.begin());
                vault_mn.erase(vault_mn.begin());
                auto it = vault_mx.lower_bound(q[i]);
                it--;
                mx.pb(*it);
                vault_mx.erase(it);
            }
            else
            {
                mn.pb(q[i]);
                mx.pb(q[i]);
                vault_mn.erase(q[i]);
                vault_mx.erase(q[i]);
            }
        }
    }
    for(auto i:mn)
        cout << i << ' ';
    cout << el;
    for(auto i:mx)
        cout << i << ' ';
    cout << el;
}
int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
        solve();
}