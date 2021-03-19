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


void zuka()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
vec(bool) steve();
ll mod_plus(ll n1, ll n2)
{
    return ((n1%mod)+(n2%mod))%mod;
}
ll mod_multiply(ll n1, ll n2)
{
    return ((n1%mod)*(n2%mod))%mod;
}
int main()
{
    zuka();
    string s;
    cin >> s;
    string code="";
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '>')code+="1000";
        else if(s[i] == '<')code+="1001";
        else if(s[i] == '+')code+="1010";
        else if(s[i] == '-')code+="1011";
        else if(s[i] == '.')code+="1100";
        else if(s[i] == ',')code+="1101";
        else if(s[i] == '[')code+="1110";
        else if(s[i] == ']')code+="1111";
    }
    ll res = 0;
    ll p = 0;
    for(int i = code.length()-1; i >= 0; i--)
    {
        int n = code[i]-'0';
        ll hld = 0;

        if(n == 1)
        {
            hld = 1;
            for(int j = 1; j <= p; j++)
            {
                hld = mod_multiply(2,hld);
            }
        }
        res = mod_plus(hld,res);
        p++;
    }
    cout << res;
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