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
const ll mod = 1000000007;
const ll MAX = 1000005;
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
    int t; cin >> t;
    while(t--)
    {
        int a,b; cin >> a >> b;
        string s; cin >> s;
        // n-(i+1)
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
                a--;
            else if(s[i] == '1')
                b--;
        }
        bool fail = false;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                if(s[n-(i+1)] == '1')
                    fail = true;
                else if(s[n-(i+1)] == '?')
                {
                    if(a)
                    {
                        a--;
                        s[n-(i+1)] = '0';
                    }
                    else
                        fail = true;
                }
            }
            else if(s[i] == '1')
            {
                if(s[n-(i+1)] == '0')
                    fail = true;
                else if(s[n-(i+1)] == '?')
                {
                    if(b)
                    {
                        b--;
                        s[n-(i+1)] = '1';
                    }
                    else
                        fail = true;
                }
            }

        }
        if(fail)
        {
            cout << -1 << el;
            continue;
        }
        else
        {
            if(n%2 == 1 && s[((n+1)/2)-1] == '?')
            {
                if(a%2 == 1 && b%2 == 1)
                    fail = true;
                else if(a%2 == 0 && b%2 == 0)
                    fail = true;
                else if(a%2)
                {
                    s[((n+1)/2)-1] = '0';
                    a--;
                }
                else if(b%2)
                {
                    s[((n+1)/2)-1] = '1';
                    b--;
                }
            }
            if(fail)
            {
                cout << -1 << el;
                continue;
            }
            else
            {
                for(int i = 0; i < n; i++)
                {
                    if(s[i] == '?')
                    {
                        if(a >= b)
                        {
                            s[i] = s[n-(i+1)] = '0';
                            a-=2;
                        }
                        else
                        {
                            s[i] = s[n-(i+1)] = '1';
                            b-=2;
                        }
                    }
                }
                if(0 > a || 0 > b)
                    cout << -1 << el;
                else
                    cout << s << el;
            }
        }
    }
}
