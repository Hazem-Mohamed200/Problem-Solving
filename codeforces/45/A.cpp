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
    vec(string)m = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string s; int k; cin >> s >> k;
    int start;
    for(int i = 1; i <= 12; i++)
    {
        if(m[i-1] == s)
        {
            start = i-1;
            break;
        }
    }
    cout << m[(start+k)%12];
}
