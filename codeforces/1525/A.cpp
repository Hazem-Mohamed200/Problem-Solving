#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define F first
#define S second
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 2e5+5; const ll mod = 1e9+7;

int main()
{
    Zuka
    int t; cin >> t;
    while(t--)
    {
        int k; cin >> k;
        int e = k, w = 100 - e;
        int g = __gcd(e,w);
        int ans = (e/g)+ (w/g);
        cout << ans << el;
    }
}