#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define F first
#define S second
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 45; const ll mod = 1e9+7;

int main()
{
    Zuka
    int t; cin >> t;
    while(t--)
    {
        ll s; cin >> s;
        ll carry = s%10;
        s -= carry;
        ll spend = 0;
        while(s >= 10)
        {
            spend += s;
            s /= 10;
            s += carry;
            carry = s%10;
            s -= carry;
        }
        cout << spend + s + carry << el;
    }
}