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
bool solve()
{
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i <= 4; i++)
    {
        string s1 = s.substr(0,i);
        int j = 4-i;
        string s2 = s.substr(n - j,4);
        if(s1+s2 == "2020")
            return true;
    }
    return false;
}
int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
        cout << (solve() ? "YES\n":"NO\n");

}