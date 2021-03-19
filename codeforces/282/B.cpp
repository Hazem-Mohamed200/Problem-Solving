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


int main()
{
    zuka();
    int n; cin >> n;
    string ans="";
    ll diff = 0;
    ll a = 0,g = 0;
    for(int i = 0; i < n; i++)
    {
        ll x,y;
        cin >> x >> y;
        if(abs((a+x)-g) <= abs((g+y)-a))
        {
            a+=x;
            ans+='A';
        }
        else
        {
            g+=y;
            ans+='G';
        }
    }
    if(abs(a-g) > 500)
        cout << -1;
    else
        cout << ans;

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