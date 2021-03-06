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

const ll N = 2e5+5; const ll mod = 1e9+7;

ll a[N], b[N];
int main()
{
    Zuka
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    map<pair<int,int>,ll>freq;
    int hld = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0 && b[i] == 0)
            hld++;
        if(a[i])
        {
            int g = __gcd(b[i],a[i]);
            b[i]/=g;
            a[i]/=g;
            freq[{b[i], a[i]}]++;
        }
    }
    ll mx = 0;
    for(auto i:freq)
    {
        mx = max(i.S, mx);
    }
    cout << mx + hld;
}