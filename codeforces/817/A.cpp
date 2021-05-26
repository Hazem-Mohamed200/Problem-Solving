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
#define file freopen("input.txt","r" , stdin),freopen("output.txt" , "w" , stdout);
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int Dx[] = {-1, -1, -1,  0, 0,  1, 1,  1};
int Dy[] = {-1,  0,  1, -1, 1, -1, 0,  1};

const ll N = 2e5+5; const ll mod = 1e9+7;


int main()
{
    Zuka
    int sx,sy,tx,ty,x,y;
    cin >> sx >> sy >> tx >> ty >> x >> y;
    int m1 = abs(sx - tx);
    int m2 = abs(sy-ty);
    if(m1%x == 0 && m2%y == 0)
    {
        m1/=x;
        m2/=y;
        if(m1%2 == m2%2)
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "NO";
}