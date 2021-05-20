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
const ll N = 2e5+5; const ll mod = 1e9+7;

int main()
{
    Zuka
    int t; cin >> t;
    vector< ll > stations;
    for(int i = 1; i <= 30; i++)
        stations.push_back(1 << i);
    while(t--)
    {
        int n; cin >> n;
        if(n == 2)
        {
            cout << 1 << el;
            continue;
        }
        else if(n == 1)
        {
            cout << 0 << el;
            continue;
        }
        auto it = lower_bound(stations.begin(), stations.end(), n);
        if(*it != n)
            it--;
        cout << *it-1 << el;
    }

}