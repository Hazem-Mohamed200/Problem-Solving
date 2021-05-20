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
const ll N = 2e5+5; const ll mod = 1e9+7;

bool isPal(string s)
{
    string h = s;
    reverse(h.begin(), h.end());
    return (h == s);
}
int counter(string s)
{
    int ones = 0;
    for(int i = 0; i < s.length(); i++)
        if(s[i] == '0')
            ones++;
    return ones;
}
int main()
{
    Zuka
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        int cnt = counter(s);

       if(cnt%2 && cnt != 1)
           cout << "ALICE\n";
       else if(cnt%2 == 0 || cnt == 1)
           cout << "BOB\n";
       else
           cout << "DRAW\n";
       
    }
}