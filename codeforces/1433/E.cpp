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
ll fact(ll n)
{
    if(n == 0)
        return 1;
    if(n <= 2)
        return n;
    if(n == 1)
        return n;
    return n*fact(n-1);
}
int main()
{
    zuka();

    int n; cin >> n;
    // 3dd el nas ely ht4ark nCn/2
    // el tartib b2a fact(n/2-1) -->  (n/2-1)! 34an in circle
    // yb2a kolo 2*(nCn/2 * (n/2-1)!
    // el C dah n!/n-n/2!*n/2!
    ll f1 = fact(n);
    ll f2 = fact(n-(n/2));
    ll f3 = fact(n/2);
    ll C = (f1)/(f2*f3);
    ll tartib = fact((n/2)-1);
    cout << (C*(tartib*tartib))/2;//tartib awl dance w tany dance
}