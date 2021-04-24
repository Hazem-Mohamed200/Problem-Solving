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
const ll MAX = 100006; const ll mod = 1000000007;
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
int freq[MAX];
int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
    {
        int n,m; cin >> n >> m;
        mms(freq,0);
        for(int i = 0; i < n; i++)
        {
            ll in; cin >> in;
            freq[in%m]++;
        }
        int ans = 0;
        if(freq[0]) ans++;
        for(int i = 1; i <= m/2; i++)
        {
//            if(m%2 == 0 && i == m/2)
//                break;
            int f1 = freq[i];
            int f2 = freq[m-i];
            if(f1 && f2)
            {
                if(max(f1,f2) > min(f1,f2)+1)
                    ans += max(f1,f2) - min(f1,f2);
                else
                    ans++;
            }
            else if(f1 || f2)
                ans += max(f1,f2);
        }
        cout << ans << el;
    }
}