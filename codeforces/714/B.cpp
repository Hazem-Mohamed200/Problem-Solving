#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define F first
#define S second
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 2e5+5; const ll mod = 1e9+7;

int main()
{
    Zuka
    int n; cin >> n;
    bool fail = false;
    set<int>nums;
    vector<int>v;
    int mx = 0, mn = 1e9;
    for(int i = 0; i < n; i++)
    {
        int in; cin >> in;
        nums.insert(in);
        mx = max(mx, in);
        mn = min(mn, in);
    }
    ll top = 0;
    for(auto i:nums)
    {
        top += i;
        v.push_back(i);
    }
    n = v.size();
    if(n == 2)
    {
        cout << "YES";
        return 0;
    }
    int key = (top+n-1)/n;
    int diff = -1;
    for(int i = 0; i < n; i++)
    {
        if(diff == -1)
        {
            diff = abs(key-v[i]);
            continue;
        }
        if(abs(key-v[i]) != diff && abs(key-v[i]))
        {
            fail = true;
            break;
        }
    }
    cout << (fail ? "NO":"YES");
}