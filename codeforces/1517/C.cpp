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
int arr[505][505];
int main()
{
    zuka();
    int n; cin >> n;
    vec(int)d(n);
    set<int>nums,numsh;
    for(int i = 0; i < n; i++)
    {
        cin >> d[i];
        nums.insert(d[i]);
    }
    int koko = 0;
    int stop = 0;
    for(int i = 0; i < n; i++)
    {
        arr[i][i] = d[koko];
        koko++;
    }
    for(int i = 0; i < n; i++)
    {
        int x = arr[i][i];
        int ctr = 1;
        int ih = i;
        for(int j = i; ctr < x; ctr++)
        {
            if(j > 0 && arr[ih][j-1] == 0)
            {
                arr[ih][j-1] = x;
                j--;
            }
            else
            {
                arr[ih+1][j] = x;
                ih++;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j])
                cout << arr[i][j] << ' ';
        }
        cout << el;
    }
}