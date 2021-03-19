#include <bits/stdc++.h>
#define mod 1000000007
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


void zuka()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
vec(bool) steve();

int main()
{
    zuka();
    int n; cin >> n;
    vec(pii)v(n);
    vec(pii)vv(n);
    for(int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        v[i].first = y;
        v[i].second = x;
        vv[i].first = x;
        vv[i].second = y;
    }
    sort(v.rbegin(),v.rend());
    sort(vv.rbegin(),vv.rend());
    ll s1=0,s2=0;
    int counter = 1;
    int i = 0;
    while(counter > 0)
    {
        s1+=vv[i].first;
        counter+=vv[i].second;
        i++;
        if(i==n)
            break;
        counter--;
    }
    counter = 1;
    i = 0;
    while(counter > 0)
    {
        s2+=v[i].second;
        counter+=v[i].first;
        i++;
        if(i==n)
            break;
        counter--;
    }
    cout << max(s1,s2);
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