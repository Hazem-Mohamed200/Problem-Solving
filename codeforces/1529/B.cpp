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
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int negative = 0, zero = 0, positive = 0;
        vector<int>neg,pos;
        for(int i = 1; i <= n; i++)
        {
            int in; cin >> in;
            if (0 > in)
            {
                negative++;
                neg.pb(in);
            }
            else if(in == 0)
            {
                zero++;
                neg.pb(0);
            }
            else
            {
                positive++;
                pos.pb(in);
            }
        }
        if(n == 1)
        {
            cout << 1 << el;
            continue;
        }
        if(negative == 0)
        {
            if(zero > 1)
                cout << zero << el;
            else
            {
                int temp = zero;
                if(positive)
                    cout << temp+1 << el;
            }
            continue;
        }
        ll ans = negative+zero;
        sort(neg.begin(), neg.end());
        int mn = 1e9, hld = abs(neg[0]);
        for(int i = 1; i < neg.size(); i++)
        {
           hld = abs(neg[i]-neg[i-1]);
           mn = min(mn, hld);
        }
        if(pos.size())
        {
            for(int i = 0; i < pos.size(); i++)
            {
                if(pos[i] <= mn)
                {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << el;

    }
}
// Hazem Mohamed