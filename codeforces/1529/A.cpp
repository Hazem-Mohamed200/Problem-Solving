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

int main()
{
    Zuka
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int mn = 1e9;
        map<int, int>freq;
        for(int i = 0; i < n; i++)
        {
            int in; cin >> in;
            freq[in]++;
            mn = min(mn, in);
        }
        int ans = 0;
        for(auto i:freq)
        {
            if(i.first != mn)
                ans += i.second;
        }
        cout << ans << el;

    }
}
// Hazem Mohamed