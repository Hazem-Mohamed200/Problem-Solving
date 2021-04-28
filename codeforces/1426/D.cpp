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
const ll N = 200005; const ll mod = 1000000007;
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
    int n; cin >> n;
    set<ll>temp;
    temp.insert(0);
    ll ans = 0;
    ll current = 0;
    for(int i = 1; i <= n; i++)
    {
        ll in; cin >> in;
        current+=in;
        if(temp.count(current))
        {
            temp.clear();
            temp.insert(0);
            current = in;
            ans++;
        }
        temp.insert(current);
    }
    cout << ans;
}