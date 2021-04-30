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
const ll N = 8; const ll mod = 1000000007;
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
        int n,m,k;
        cin >> n >> m >> k;
        ll cost = 0;
           cost += n-1;
           for(int i = 1; i <= m-1; i++)
               cost += n;
           if(cost == k)
               cout << "YES\n";
           else
           {
               cost = 0;
               cost += m - 1;
               for (int i = 1; i <= n-1; i++)
                   cost += m;
               if (cost == k)
                   cout << "YES\n";
               else
                   cout << "NO\n";
           }

    }
}