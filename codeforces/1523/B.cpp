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
    vector<int>v;
    for(int i = 0; i < n; i++)
    {
        int in; cin >> in;
        v.push_back(in);
    }
    cout << 6*(n/2) << el;
    for(int i = 0; i < n; i++)
    {
        cout << 2 << ' ' << i+1 << ' ' << i+2 << el;
        cout << 1 << ' ' << i+1 << ' ' << i+2 << el;
        cout << 2 << ' ' << i+1 << ' ' << i+2 << el;
        cout << 1 << ' ' << i+1 << ' ' << i+2 << el;
        cout << 2 << ' ' << i+1 << ' ' << i+2 << el;
        cout << 1 << ' ' << i+1 << ' ' << i+2 << el;
        i++;
    }
}
int main()
{
    Zuka
    int t = 1;
    cin >> t;
    while(t--)
        testCase();
}