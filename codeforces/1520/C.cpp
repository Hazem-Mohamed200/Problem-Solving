#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define F first
#define S second
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 105; const ll mod = 1e9+7;

int arr[N][N];
int main()
{
    Zuka
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        if(n == 2)
        {
            cout << -1 << el;
            continue;
        }
        memset(arr, 0, sizeof arr);
        vector<int>e,o;
        for(int i = 1; i <= n*n; i++)
        {
            if(i%2)
                o.push_back(i);
            else
                e.push_back(i);
        }
        for(int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(o.size())
                    arr[i][j] = o.back(), o.pop_back();
                else
                    arr[i][j] = e.back(), e.pop_back();
            }
        }
        for(int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << ' ';
            }
            cout << el;
        }
    }
}