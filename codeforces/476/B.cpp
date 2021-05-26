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
const ll N = 15; const ll mod = 1e9+7;

int tot;
string s1, s2;
int dp[15][30];
int target = 0;
int pos = 0;
int cnt = 0;
ll fact(int n)
{
    if(n <= 1)
        return 1;
    else
        return n * fact(n-1);
}
void solve()
{

    for(int i = 1; i <= 10; i++)
    {
        for(int p = 0; p <= i; p++)
        {
            int m = i-p;
            dp[i][10 + (p-m)] = (fact(p+m)/(fact(p) * fact(m)));
        }
    }

}
int main()
{
    Zuka
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++)
    {
        if(s1[i] == '+')
            target++;
        else
            target--;


        if(s2[i] == '+')
            pos++;
        else if(s2[i] == '-')
            pos--;
        else
            cnt++;
    }
    tot = 1 << cnt;
    cout << fixed << setprecision(12);
    solve();
    if(cnt)
        cout << (float)dp[cnt][10 + (target-pos)]/(float)tot;
    else if(cnt == 0 && target == pos)
        cout << (float)1;
    else 
        cout << (float )0;
}