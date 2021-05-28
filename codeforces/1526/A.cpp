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
const ll N = 1e5+5; const ll mod = 1e9+7;

void testCase()
{
    int n; cin >> n;
    vector<ll>v;
    for(int i = 0; i < 2*n; i++)
    {
        ll in; cin >> in;
        v.pb(in);
    }
    sort(v.begin(), v.end());
    for(int i = 2; i < 2*n; i++)
    {
        if(i == 2*n-1)
            break;
      swap(v[i-1],v[i]);
      i++;
    }
    for(int i = 0; i < 2*n; i++)
        cout << v[i] << ' ';
    cout << el;
}
int main()
{
    Zuka
    int t; cin >> t;
    while(t--)
        testCase();

}