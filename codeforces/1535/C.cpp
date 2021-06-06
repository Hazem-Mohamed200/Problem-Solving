#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define F first
#define S second
#define pb push_back
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "wt", stdout);

//const ll INF = LONG_LONG_MAX;
const ll N = 2e5+5; const ll mod = 1e9+7;

void handle(ll& add, ll& ans, char& last, char curr, ll& qcnt, char& ql, char& qr)
{
    if(last == curr)
        add = 1;
    else if(last == '?')
    {
        qr = curr;

        if(ql == '*')
        {
            add++;
            return;
        }
        if(qcnt % 2 == 0)
        {
            if(ql == qr)
                add = qcnt+1, qcnt = 0;
            else
                add++, qcnt = 0;
        }
        else
        {
            if(ql != qr)
                add = qcnt+1, qcnt = 0;
            else
                add++, qcnt = 0;
        }
        ql = '*';
    }
    else
        add++;

    return;
}
void testCase()
{
    string s; cin >> s;
    int n = s.length();

    ll ans = 1;
    char last = s[0];
    ll add = 1, qcnt = 0;
    char ql = '*', qr = '*';

    if(last == '?')
        qcnt++;

    for(int i = 1; i < n; i++)
    {
        if(s[i] == '?')
        {
            if(ql == '*' && last != '?')
                ql = last, qcnt = 0;

            qcnt++;
            add++;
        }
        else
            handle(add, ans, last, s[i], qcnt, ql, qr);

        ans += add;
        last = s[i];
    }
    cout << ans << el;
}
int main()
{
    Zuka
    int t = 1;
    cin >> t;
    while(t--)
        testCase();
}