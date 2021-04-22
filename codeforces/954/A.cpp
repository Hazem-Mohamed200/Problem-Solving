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
const ll MAX = 500100; const ll mod = 1000000007;
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
    int n; cin >> n;
    string s; cin >> s;
    string hld;
    for(int i = 0; i < n-1; i++)
    {
        if((s[i] == 'U' && s[i+1] == 'R') || (s[i] == 'R' && s[i+1] == 'U'))
        {
            hld+='D';
            s[i]='*'; s[i+1]='*';
            i++;
        }
        else
            hld+=s[i];
    }
    if(s[n-1] != '*')
        hld += s[n-1];
    cout << hld.size();
}