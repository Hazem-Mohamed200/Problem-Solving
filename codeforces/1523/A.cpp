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
const ll N = 2e5+5; const ll mod = 1e9+7;


void testCase()
{
    int n, m; cin >> n >> m;
    string s; cin >> s;
    for(int k = 0; k < m; k++)
    {
        vector<int>change;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                if (i == 0) {
                    if (s[i + 1] == '1')
                        change.pb(i);
                } else if (i == n - 1) {
                    if (s[i - 1] == '1')
                        change.pb(i);
                } else {
                    if ((s[i - 1] == '1' && s[i + 1] != '1') || (s[i - 1] != '1' && s[i + 1] == '1'))
                        change.pb(i);
                }
            }
        }
        if(change.size()) {
            for (auto j:change)
                s[j] = '1';
        }
        else
            break;
    }
    cout << s << el;
}
int main()
{
    Zuka
    int t = 1;
    cin >> t;
    while(t--)
        testCase();
}