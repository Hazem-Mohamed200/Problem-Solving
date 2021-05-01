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
int dx[8]= {-1, -1, -1,  0, 0,  1, 1,  1};
int dy[8]= {-1,  0,  1, -1, 1, -1, 0,  1};
const ll N = 200005; const ll mod = 1000000007;

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
    int hour,m,hunger,d,Cost,n;
    cin >> hour >> m;
    ll time = (hour*60)+m;
    cin >> hunger >> d >> Cost >> n;
    cout << fixed << setprecision(4);
    //20:00 is at 1200
    // Current hunger : H
    // Each min --> H += D
    // 1 Bread cost C and reduce H by N
    // 4of anhy a7sn a4try kolo abl el discount wla b3do
    float costd = float(Cost)*(float)0.8;
    float cost = Cost;
    if(time < 1200)
    {
        int b1 = (hunger+n-1)/n;
        float ans1 = b1*cost;
        int hld = 1200-time;
        hunger = hunger+(d*hld);
        int b2 = (hunger+n-1)/n;
        float ans2 = b2*costd;
        cout << min(ans1,ans2);
    }
    else
    {
        float ans = ((hunger+n-1)/n)*(costd);
        cout << ans;
    }

}
