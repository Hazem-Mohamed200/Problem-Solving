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
int dx[]= {0, 1, 0, -1};
int dy[]= {1, 0, -1, 0};
const ll MAX = 4; const ll mod = 1000000007;
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
string s1,s2;
int ctr = 0;
int pos = 0;
int tot = 0;
void solve(int index,int p)
{
    if(index == s2.length() && p == pos)
    {
        tot++;
        ctr++;
        return;
    }
    else if(index == s2.length() && p != pos)
    {
        tot++;
        return;
    }

    if(s2[index] == '?')
    {
       solve(index+1,p+1);
       solve(index+1,p-1);
    }
    else if(s2[index] == '+')
        solve(index + 1,p + 1);
    else
        solve(index + 1,p - 1);
}
int main()
{
    zuka();
    cin >> s1 >> s2;
    int p2 = 0;
    for(int i = 0; i < s1.length(); i++)
    {
        if(s1[i] == '+')
            pos++;
        else
            pos--;

        if(s2[i] == '+')
            p2++;
        else if(s2[i] == '-')
            p2--;
    }

    int hld = 0;
    for(int i = 0; i < s2.length(); i++)
        if(s2[i] == '?')
            hld++;
    solve(0,0);
    cout << fixed << setprecision(12);
    if(hld)
        cout << (float)ctr/(float)tot;
    else if(pos == p2)
        cout << (float)1;
    else
        cout << (float)0;
}