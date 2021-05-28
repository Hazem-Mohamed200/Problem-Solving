#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define F first
#define S second
#define pb push_back
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 2000+5; const ll mod = 1e9+7;


void testCase()
{
     ll n; cin >> n;
     if(n > 1099)
     {
         cout << "YES\n";
         return;
     }
     for(int i = 0; i <= 101; i++)
     {
         ll x = (ll)11*(ll)i;
         for(int j = 0; j <= 101; j++)
         {
             if(x + ((ll)111*(ll)j) == n)
             {
                 cout << "YES\n";
                 return;
             }
             else if(x + ((ll)111*(ll)j) > n)
                 break;
         }
     }
     cout << "NO\n";
}
int main()
{
    Zuka
  int t;
    cin >> t;
    while(t--)
       testCase();
}