#include <bits/stdc++.h>
using namespace std;
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
#define file freopen("input.txt","r" , stdin),freopen("output.txt" , "w" , stdout);
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int Dx[] = {-1, -1, -1,  0, 0,  1, 1,  1};
int Dy[] = {-1,  0,  1, -1, 1, -1, 0,  1};


const ll N = 1e3+5; const ll mod = 1e9+7;


int main()
{
    Zuka
    int t; cin >> t;
    while(t--)
    {
        ll n, ans = 0; cin >> n;
        string s; cin >> s;
        vec(int)stairs;
        for(int i = 0; i < n; i++)
            if(s[i] == '1')
                stairs.pb(i+1);

        if(!stairs.size())
        {
            cout << n << el;
            continue;
        }
        else
        {
            for(auto i:stairs)
            {
                ll temp1 = 2*i;
                ll temp2 = 2*(n-i+1);
                ans = max(ans, max(temp1, temp2));
            }
        }
        cout << ans << el;
    }
}