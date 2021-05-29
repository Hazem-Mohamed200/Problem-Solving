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
const ll N = 100+5; const ll mod = 1e9+7;

pair<int, pair<int, int>>arr[N];
void testCase()
{
    int n, temp; cin >> n >> temp;
    bool can = true;
    for(int i = 1; i <= n; i++)
    {
        int t, l, r, window;
        cin >> t >> l >> r;
        arr[i] = {t, {l,r}};
    }
    int time = 0;
    ll mx = temp, mn = temp;
    for(int i = 1; i <= n; i++)
    {
        ll t = arr[i].F, l = arr[i].S.F, r = arr[i].S.S, window = t - time;
        mn = mn - window, mx = mx + window;
        if(mn <= r && mx >= l)
        {
            mn = max(mn, l);
            mx = min(mx, r);
        }
        else
            can = false;
        time = t;
    }
    cout << (can ? "YES\n":"NO\n");
}
int main()
{
    Zuka
    int t = 1;
    cin >> t;
    while(t--)
       testCase();
}