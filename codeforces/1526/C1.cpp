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
const ll N = 2000+5; const ll mod = 1e9+7;


void testCase()
{

    int n; cin >> n;
    priority_queue<ll>negs;
    vector<ll>v;
    ll hp = 0, ans = 0;
    for(int i = 0; i < n; i++)
    {
        ll in; cin >> in;
        v.pb(in);
    }
    for(int i = 0; i < n; i++)
    {
        if(v[i] >= 0)
            hp += v[i], ans++;
        else
        {
            if(hp + v[i] >= 0)
            {
                hp += v[i], ans++;
                negs.push(-v[i]);
            }
            else
            {
                if(negs.size() && -negs.top() < v[i])
                {
                    hp += negs.top();
                    ans--;
                    negs.pop();
                    i--;
                }
            }
        }
    }
    cout << ans;
}
int main()
{
    Zuka
  int t = 1;
    while(t--)
        testCase();
}