#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 2e5+10, length = 25 , mod = 1e9+7;
ll a[N], ans[N];
vector< int > st[N];
int main() {
    Tsetso
    int t;
     cin >> t ;
      while (t--)
      {
          int n ;
          cin >> n ;
          for ( int i= 0 ; i  < n ; i++) {
              cin >> a[i];
          }
          for ( int i = 0 ; i < n;  i++)
          {
              ll x;
              cin >> x ;
              st[a[i]].push_back(x);
          }
          for (  int i= 1 ; i <= n ; i++)
          {
              if (st[i].empty())
                  continue;
              sort(st[i].rbegin(),st[i].rend());
              vector < ll > b(st[i].size()+1 ,0);
              ll cnt = 0 , prefix=  0;
              for ( auto j : st[i])
              {
                  cnt++ ;
                  prefix += j ;
                  b[cnt] = prefix;
              }
              st[i].clear();
              for ( int k = 1 ; k < b.size() ; k++)
              {
                  ll mx = 0 ;
                  for ( int j = k ; j < b.size() ; j +=k) {
                      mx = max(b[j], mx);
                  }
                  ans[k] += mx ;
              }
          }
          for ( int i = 1 ; i <= n ; i++)
                cout << ans[i] << ' ',ans[i] = 0;
          cout << '\n';
      }
}