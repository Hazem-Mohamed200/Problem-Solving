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

bool isPal(string s)
{
    string h = s;
    reverse(s.begin(), s.end());

    return h == s;
}
void testCase()
{
    string s; cin >> s;
    int cnt = count(s.begin(), s.end(), 'a');
    if(cnt == s.length())
    {
        cout << "NO\n";
        return;
    }
    if(!isPal('a' + s))
        cout << "YES" << el << 'a' + s << el;
    else
        cout << "YES" << el << s + 'a' << el;
}
int main()
{
    Zuka
    int t = 1;
    cin >> t;
    while(t--)
        testCase();
}