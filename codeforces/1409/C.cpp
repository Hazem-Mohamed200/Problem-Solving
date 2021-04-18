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
const ll MAX = 100000; const ll mod = 1000000007;
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
       int n,x,y; cin >> n >> x >> y;
       vec(int)divs;
       if(n == 2)
       {
           cout << x << ' ' << y << el;
           continue;
       }
       for(int i = 1; i <= y-x; i++)
       {
           if((y-x)%i == 0)
                divs.pb(i);
       }
       for(int i = 0; i < divs.size(); i++)
       {
           int diff = divs[i];
           bool done = false;
           bool found = false;
           vec(int)ans;
           int next = y-diff;
           int cur = y;
           while(ans.size() < n && cur > 0)
           {
               if(cur == x)
                   found = true;
               ans.pb(cur);
               cur = next;
               next -= diff;
           }
           if(found && ans.size() == n)
           {
               for(auto j:ans)
                   cout << j << ' ';
               cout << el;
               break;
           }
           else if(found && ans.size() != n)
           {
               cur = y+diff;
               next = cur+diff;
               while(ans.size() != n)
               {
                   ans.pb(cur);
                   cur = next;
                   next += diff;
               }
               for(auto j:ans)
                   cout << j << ' ';
               cout << el;
               break;
           }
           else if(!found)
               continue;
       }
    }
}