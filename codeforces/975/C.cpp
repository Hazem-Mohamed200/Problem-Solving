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
int n,q;
int idx = 1,hld = 0;
ll arrows;
ll arr[N];
ll prefix[N];
ll alive()
{
    if(arr[idx] > arrows+hld)
    {
        hld += arrows; // hld ely madrob 3alina
        return n-idx+1;
    }
    int s = idx, e = n, mid, res;
    while(s <= e)
    {
        mid = (s+e) >> 1;
        if(prefix[mid] - (prefix[idx - 1] + hld) <= arrows)//myn a5r wa7d haymot/yst7ml
        {
            res = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    if(res == n)//kolo mat
    {
        hld = 0;
        idx = 1;
        return n;
    }
    // lw a5r 7d haymot res
    res++;
    ll damage = prefix[res] - (prefix[idx - 1] + hld + arrows);
    hld = arr[res]-damage;
    idx = res; // dah awl wa7d 3ay4 dlwa2ty
    return n-idx+1;

}
int main()
{
    zuka();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        prefix[i] = prefix[i-1]+arr[i];
    }
    for(int i = 0; i < q; i++)
    {
        cin >> arrows;
        cout << alive() << el;
    }
}
