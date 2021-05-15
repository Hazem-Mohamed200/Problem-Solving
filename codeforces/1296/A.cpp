#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define F first
#define S second
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 45; const ll mod = 1e9+7;

int main()
{
    Zuka
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int>v(n);
        ll sum = 0;
        int e = 0, o = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
            if(v[i] % 2)
                o++;
            else
                e++;
        }
        if(sum%2)
            cout << "YES\n";
        else
        {
            if(e == 0 || o == 0)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}