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
const ll N = 200005; const ll mod = 1000000007;
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

    //mn number ya3ny tl3b we74
    // tl3b kol el rock bta3ha w2t el paper 3ndo and so on...
    ll n;
    ll ar,as,ap,br,bs,bp;
    cin >> n;
    cin >> ar >> as >> ap;
    cin >> br >> bs >> bp;
    ll won = 0,lost = 0;
    won += min(ar,bs);
    won += min(as,bp);
    won += min(ap,br);
    lost += max((ll)0,ar-br-bp);
    lost += max((ll)0,as-bs-br);
    lost += max((ll)0,ap-bs-bp);
    cout << lost << ' ' << won;
}