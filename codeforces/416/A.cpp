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
    ll mx = 2e9, mn = -2e9;
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        ll num; cin >> num;
        char ans; cin >> ans;
        if(s == ">")
        {
            if(ans == 'Y')
                mn = max(mn, num+1);
            else
                mx = min(mx, num);
        }
        else if(s == ">=")
        {
            if(ans == 'Y')
                mn = max(mn, num);
            else
                mx = min(mx, num-1);
        }
        else if(s == "<")
        {
            if(ans == 'Y')
                mx = min(mx, num-1);
            else
                mn = max(mn, num);
        }
        else if(s == "<=")
        {
            if(ans == 'Y')
                mx = min(mx, num);
            else
                mn = max(mn, num+1);
        }
    }
    if(mx >= mn)
        cout << mx;
    else
        cout << "Impossible";
}
int main()
{
    Zuka
    int t = 1;
    //cin >> t;
    while(t--)
        testCase();
}