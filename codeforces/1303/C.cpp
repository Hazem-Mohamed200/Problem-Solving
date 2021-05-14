#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 205; const ll mod = 1e9+7;

string s;
bool vis[26];
char hld [100];
void solve()
{
    cin >> s;
    memset(hld, 0, 100);
    memset(vis, false, 26);
    int p = 50;
    hld[p] = s[0];
    vis[s[0] - 'a'] = true;
    for(int i = 1; i < s.length(); i++)
    {
        if(vis[s[i] - 'a'])
        {
            if(hld[p-1] == s[i])
                p--;
            else if(hld[p+1] == s[i])
                p++;
            else
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {
            if(!hld[p-1])
                p--;
            else if(!hld[p+1])
                p++;
            else
            {
                cout <<"NO\n";
                return;
            }
            vis[s[i] - 'a' ] = true;
            hld[p] = s[i];
        }
    }
    string ans = "", tail = "";
    for(int i = 0; i < 100; i++)
    {
        if(hld[i])
            ans += hld[i];
    }
    for(int i = 0; i < 26; i++)
    {
        if (!vis[i])
            tail += i + 'a';
    }
    cout  << "YES\n" << ans << tail << el;

}
int main()
{
    Zuka
    int t; cin >> t;
    while(t--)
        solve();
}