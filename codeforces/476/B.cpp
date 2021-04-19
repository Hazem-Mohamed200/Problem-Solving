#include <bits/stdc++.h>
#define el '\n'
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pff pair<float,float>
#define F first
#define S second
#define vec(int) vector<int>
#define pb push_back
#define pf push_front
#define mms(v,i) memset(v, i, sizeof v)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
const ll MAX = 100000; const ll mod = 1000000007;
using namespace std;

void file()
{
    freopen("input.txt","r" , stdin);
    freopen("output.txt" , "w" , stdout);
}
void zuka()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    zuka();
    string s,t;
    cin >> s >> t;
    int POS = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '+')
            POS++;
        else
            POS--;
    }
    int SZ = 0;
    for(int i = 0; i < t.length(); i++)
        if(t[i] == '?')
            SZ++;
    int ans = 0;
    for(int mask = 0; mask < (1 << SZ); mask++)
    {
        int pos = 0;
        int pctr = 0,mctr = 0;
        for(int bit = 0; bit < SZ; bit++)
        {
            if((mask >> bit)&1)
                pos++;
            else
                pos--;
        }
        for(int i = 0; i < t.length(); i++)
        {
            if(t[i] == '+')
                pos++;
            else if(t[i] == '-')
                pos--;
        }
        if(pos == POS)
            ans++;
    }
    cout << fixed << setprecision(12);
    cout << (double)ans/(double)(1 << SZ);
}
