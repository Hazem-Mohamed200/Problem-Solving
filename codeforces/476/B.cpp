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

int main()
{
    Zuka
    string s1, s2;
    cin >> s1 >> s2;
    int target = 0;
    int x = 0;
    int pos = 0;

    for(int i = 0; i < s1.length(); i++)
    {
        if(s1[i] == '+')
            target++;
        else
            target--;
        if(s2[i] == '?')
            x++;
        else if(s2[i] == '+')
            pos++;
        else
            pos--;
    }
    int dp[30][30];
    memset(dp, 0, sizeof dp);
    // -4 -2 0 2 4
    dp[0][s1.length()] = 1;
    for(int i = 0; i < s1.length(); i++)
    {
        for(int j = 0; j <= 2*s1.length(); j++)
        {
            if(dp[i][j]) // ya3ny 0
            {
                if(s2[i] == '+')
                {
                    dp[i+1][j+1] += dp[i][j];
                }
                else if(s2[i] == '-')
                {
                    dp[i+1][j-1] += dp[i][j];
                }
                else
                {
                    dp[i+1][j+1] += dp[i][j];
                    dp[i+1][j-1] += dp[i][j];
                }
            }
        }
    }
    cout << fixed << setprecision(12) << (float)dp[s1.length()][s1.length() + target]/(float)(1 << x);
}