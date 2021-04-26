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
const ll MAX = 1000006; const ll mod = 1000000007;
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
int n;
string koko;
int solve(string s, char key)
{
    if(s.size() == 1)
    {
        if(s[0] == key)
            return 0;
        else
            return 1;
    }
    string left = s.substr(0, s.size() / 2);
    string right = s.substr(s.size() / 2);
    int lctr = 0, rctr = 0;
    for(int i = 0; i < left.size(); i++)
    {
        if(left[i] != key)
            lctr++;
    }
    for(int i = 0; i < right.size(); i++)
    {
        if(right[i] != key)
            rctr++;
    }
    return min(solve(left, key + 1)+rctr, solve(right, key + 1)+lctr);
}
int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
    {
        cin >> n >> koko;
        cout << solve(koko, 'a') << el;
    }
}