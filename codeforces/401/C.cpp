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
const ll MAX = 4; const ll mod = 1000000007;
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
    int zero,one;
    cin >> zero >> one;
    string ans = "";
    if(zero-1 <= one && one <= 2*(zero+1))
    {
        if(zero == one)
        {
            while(zero&&one)
            {
                ans +="10";
                zero--;
                one--;
            }
            cout << ans;
        }
        else if(one == zero-1)
        {
            while(zero&&one)
            {
                ans +="01";
                zero--;
                one--;
            }
            ans += '0';
            cout << ans;
        }
        else if(one > zero && one <= 2*(zero+1))
        {
            while(zero&&one)
            {
                ans +="10";
                zero--;
                one--;
            }
            //cout << ans << el << zero << ' ' << one;
            string hld = "";
            for(int i = 0; i < ans.size(); i++)
            {
                hld += ans[i];
                if(ans[i] == '1' && one)
                {
                    hld += '1';
                    one--;
                }
            }
           while(one)
           {
               hld += '1';
               one--;
           }
           cout << hld;
        }
    }
    else
        cout << -1;
}