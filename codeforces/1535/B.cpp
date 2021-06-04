#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define F first
#define S second
#define pb push_back
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "wt", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 1e5+5; const ll mod = 1e9+7;

void testCase()
{
    int n; cin >> n;
    vector<int>e,o,v;
    for(int i = 0; i < n; i++)
    {
        int in; cin >> in;
        if(in%2 == 0)
            e.push_back(in);
        else
            o.push_back(in);
    }
    for(int i = 0; i < e.size(); i++)
        v.pb(e[i]);
    for(int i = 0; i < o.size(); i++)
        v.pb(o[i]);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(__gcd(v[i],2*v[j]) > 1)
                ans++;
        }
    }
    cout << ans << el;

}
int main()
{
    Zuka
    int t = 1;
    cin >> t;
    while(t--)
        testCase();
}