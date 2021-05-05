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
int dx[8] = {-1, -1, -1,  0, 0,  1, 1,  1};
int dy[8] = {-1,  0,  1, -1, 1, -1, 0,  1};
const ll N = 44; const ll mod = 1000000007;

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
void step(int& a, int& b, int q)
{
    int step = a - b * q;
    a = b;
    b = step;
}
ll fsp(int b, int p)
{
    if(p == 1)
        return b;
    ll temp = fsp(b, p / 2);
    if(p%2)
        return temp*temp*b;
    else
        return temp*temp;

}
int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
    {
        ll n,k; cin >> n >> k;
        vec(int)divs;
        divs.pb(1);
        for(ll i = 2; i*i <= n; i++)
        {
            if(n%i == 0)
            {
                divs.pb(i);
                if (n / i != i)
                    divs.pb(n / i);
            }
        }
        divs.pb(n);
        sort(all(divs));
        int s = 0, e = divs.size()-1, mid,res = 0;
        while(s<=e)
        {
            mid = (s+e) >> 1;
            if(divs[mid] <= k)
            {
                res = max(res,divs[mid]);
                s = mid+1;
            }
            else
                e = mid-1;
        }

        cout << n/res << el;
    }
}
