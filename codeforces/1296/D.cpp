#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define F first
#define S second
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 2e5 + 5; const ll mod = 1e9+7;

int main()
{
    Zuka
    ll n,a,b,k;
    ll points = 0;
    cin >> n >> a >> b >> k;
    vector<ll>unsafe;
    multiset<ll>hld;
    for(int i = 0; i < n; i++)
    {
        ll in; cin >> in;
        in = in%(a+b);
        if(in % (a+b) == 0)
            in = a+b;
        unsafe.push_back(((in+a-1)/a) - 1);
    }
    sort(unsafe.begin(), unsafe.end());
    for(int i = 0; i < unsafe.size(); i++)
    {
        if(k - unsafe[i] >= 0)
        {
            points++;
            k -= unsafe[i];
        }
        else
            break;
    }
    cout << points << el;
}