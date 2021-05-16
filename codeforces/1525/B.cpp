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
        int n; cin >> n;
        vector<int>v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        vector<int>c(v);
        sort(c.begin(), c.end());
        bool sorted = true;
        for(int i = 0; i < n; i++)
        {
            if(v[i] != c[i])
            {
                sorted = false;
                break;
            }
        }
        if(sorted)
            cout << 0 << el;
        else
        {
            if(v[0] == 1 || v[n-1] == n)
            {
                cout << 1 << el;
                continue;
            }
            if(v[n-1] == 1 && v[0] != n)
            {
                cout << 2 << el;
                continue;
            }
            if(v[0] == n && v[n-1] == 1)
            {
                cout << 3 << el;
                continue;
            }
            cout << 2 << el;
        }
    }
}