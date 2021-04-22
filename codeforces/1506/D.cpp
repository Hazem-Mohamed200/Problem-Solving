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
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int nh = n;
        map<ll,ll>freq;
       priority_queue<pll>q;
        for(int i = 0; i < n; i++)
        {
            ll in; cin >> in;
            freq[in]++;
        }
        for(auto it = freq.begin(); it != freq.end(); it++)
        {
            ll ff = it->S;
            ll num = it->F;
            q.push({ff,num});
        }
        ll sz = n;
        while(q.size() >= 2)
        {
            ll f1 = q.top().F;
            ll n1 = q.top().S;
            q.pop();
            ll f2 = q.top().F;
            ll n2 = q.top().S;
            q.pop();
            f1--;
            f2--;
            sz -= 2;
            if(f1)
                q.push({f1,n1});
            if(f2)
                q.push({f2,n2});
        }
        cout << sz << el;
    }
}