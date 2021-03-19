#include <bits/stdc++.h>
#define mod 1000003 //1000000007
#define el '\n'
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define vec(int) vector<int>
#define pb push_back
#define pf push_front
#define mms(v,i) memset(v, i, sizeof v)
#define MAX 100005
#define sieve vec(bool)primes = steve();
using namespace std;
vec(bool) steve();
ll mod_plus(ll n1, ll n2);
ll mod_multiply(ll n1, ll n2);

void zuka()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

}
int fun(vec(int)v,int target,int tool)
{
    int ctr = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] < target)
        {
            while(v[i] < target)
            {
                v[i]+=tool;
                ctr++;
            }
        }
        else if(v[i] > target)
        {
            while(v[i] > target)
            {
                v[i]-=tool;
                ctr++;
            }
        }
        if(v[i] != target)
            return -1;
    }
    return ctr;
}

int main()
{
    zuka();
    int rows,columns,d,mn=10000,mx=0;
    cin >> rows >> columns >> d;
    int arr[105][105]={};
    vec(int)v;
    bool flag = true;
    for(int i = 0; i < rows; i++)
    {
        for(int j =  0; j < columns; j++)
        {
            cin >> arr[i][j];
            v.pb(arr[i][j]);
            mn = min(mn,arr[i][j]);
            mx = max(mx,arr[i][j]);
        }
    }

    int ctr = 0;
    int n = v.size();
    sort(v.begin(),v.end());
    int target;
    if(n%2 == 0)
    {
        int t1 = v[(n-1)/2];
        int t2 = v[n/2];
        int res1 = fun(v,t1,d);
        int res2 = fun(v,t2,d);
        if(res1 == -1 && res2 == -1)
            ctr = -1;
        else if(res1 > -1 && res2 == -1)
            ctr = res1;
        else if(res2 > -1 && res1 == -1)
            ctr = res2;
        else
            ctr = min(res1,res2);

    }
    else
    {
        target = v[(n-1)/2];
        ctr = fun(v,target,d);
    }
    cout << ctr;




}


















vec(bool) steve()
{
    vec(bool)primes(MAX,1);
    for(ll i = 2; i*i <= MAX; i++)
    {
        if(primes[i])
        {
            for(ll j = i*i; j <= MAX; j+= i)
                primes[j]=0;
        }
    }
    primes[0] = primes[1] = 0;
    return primes;
}
ll mod_plus(ll n1, ll n2)
{
    return ((n1%mod)+(n2%mod))%mod;
}
ll mod_multiply(ll n1, ll n2)
{
    return ((n1%mod)*(n2%mod))%mod;
}