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
    int n; cin >> n;
    set<ll>s;
    vec(ll)v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(all(v));
    for(int i = 0; i < n; i++)
    {
        if(v[i] == 1)
        {
            if(s.count(1))
                s.insert(2);
            else
                s.insert(1);
        }
        else
        {
            if(s.count(v[i]-1) == 0)
                s.insert(v[i]-1);
            else if(s.count(v[i]) == 0)
                s.insert(v[i]);
            else
                s.insert(v[i]+1);
        }
    }
    cout << s.size();
}