#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define F first
#define S second
#define pb push_back
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 1e5 + 5; const ll mod = 1e9+7;

int n,d;
vector<pair<ll ,ll >>friends;
ll prefix[N] = { 0 };
ll bs(int s)
{
    int sh = s;
    ll e = n-1, mid, res = 0;
    while(s <= e)
    {
        mid = (s+e) >> 1;
        if(friends[mid].first - friends[sh].first >= d)
            e = mid - 1;
        else
        {
            res = max(res, prefix[mid]-(sh == 0 ? 0:prefix[sh-1]));
            s = mid + 1;
        }
    }
    return res;
}
int main()
{
    Zuka
    cin >> n >> d;
    for(int i = 0; i < n; i++)
    {
        ll s,m; cin >> m >> s;
        friends.push_back({m, s});
    }
    sort(friends.begin(), friends.end());
    for(int i = 0; i < n; i++)
    {
        if(i)
            prefix[i] = prefix[i-1] + friends[i].second;
        else
            prefix[i] = friends[i].second;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans,bs(i));

    cout << ans;

}
// Hazem Mohamed