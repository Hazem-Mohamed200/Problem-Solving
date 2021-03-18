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
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        bool lock1 = false;
        bool flag = false;
        int eve=0;
        int uwu=0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i]=='1')
                eve++;
            else
                eve=0;

            if(eve == 2)
                lock1 = true;

            if(s[i]=='0' && lock1)
                uwu++;
            else if(s[i]=='1' && lock1)
                uwu=0;

            if(uwu == 2)
            {
                cout << "NO\n";
                flag = true;
                break;
            }
        }
        if(!flag)
            cout << "YES\n";
    }
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