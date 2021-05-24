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
    int n; cin >> n;
    int hld; cin >> hld;
    int ans = 0;
    int temp = 1;
    for(int i = 1; i <= n-1; i++)
    {
        int in; cin >> in;
        if(in >= hld)
            temp++;
        else
        {
            ans = max(temp, ans);
            temp = 1;
        }
        hld = in;
    }
    ans = max(ans, temp);
    cout << ans;

}
// Hazem Mohamed