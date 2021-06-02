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
        if(in == 1)
            v.pb(in);
        else
        {
            while(v.size() && v.back() != in-1)
                v.pop_back();
            if(v.size() && v.back() == in - 1)
                v.pop_back();
            v.pb(in);
        }
        for(int j = 0; j < v.size(); j++)
        {
            if(j)
                cout << '.';
            cout << v[j];
        }
        cout << el;
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