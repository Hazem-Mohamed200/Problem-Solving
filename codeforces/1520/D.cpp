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
        ll n, ctr = 0; cin >> n;
        map<ll, ll>freq;
        for(int i = 1; i <= n; i++)
        {
            int in; cin >> in;
            freq[in-i]++;
        }
        for(auto i:freq)
            ctr += (i.S*(i.S-1))/2;
        cout << ctr << el;
    }
}