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
        int n; cin >> n;
        ll sum = 0,sumh = 0;
        vec(ll)b;
        multiset<ll>ms;
        for(int i = 0; i < n+2; i++)
        {
            int in; cin >> in;
            b.pb(in);
            ms.insert(in);
            sum += b[i];
        }
        sort(all(b));
        bool fail = true;
        int k1,k2;
        for(int i = 0; i < n+2; i++)
        {
            ms.erase(ms.find(b[i]));
            sumh = sum;
            sumh -= b[i];
            if(sumh > b[i])
            {
                auto it = ms.find(sumh-b[i]);
                if(it == ms.end())
                {
                    ms.insert(b[i]);
                    continue;
                }
                else
                {
                    fail = false;
                    k1 = b[i];
                    k2 = sumh - b[i];
                    break;
                }
            }
            else
                continue;
        }
        if(fail)
            cout << -1 << el;
        else
        {
            for(int i = 0; i < b.size(); i++)
            {
                if(b[i] == k1)
                {
                    k1 = 0;
                    continue;
                }
                else if(b[i] == k2)
                {
                    k2 = 0;
                    continue;
                }
                else
                    cout << b[i] << ' ';
            }
            cout << el;
        }

    }
}
