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
    vector<int>arr(4);
    int mx1 = 0, mx2 = 0;
    for(int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }
    int w1, w2;
    w1 = max(arr[0], arr[1]);
    w2 = max(arr[2], arr[3]);
    sort(arr.rbegin(), arr.rend());
    if((w1 == arr[0] && w2 == arr[1]) || (w1 == arr[1] && w2 == arr[0]))
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    Zuka
    int t = 1;
    cin >> t;
    while(t--)
        testCase();
}