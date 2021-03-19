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
    int arr[MAX]={};
    int fre[MAX][3]={};
    vec(int)v(n);
    vec(pii)res;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        fre[v[i]][0]++;
        if(fre[v[i]][0] == 1)
            fre[v[i]][1]=i;
        else if(fre[v[i]][0] == 2)
            fre[v[i]][2]=i;
    }
    for(int i = 0; i < n; i++)
    {
        int key = v[i];
        int freq = fre[key][0];
        int floc = fre[key][1];
        int lloc = fre[key][2];
        bool flag = true;

        if(arr[key] == 0)
        {
            if(freq == 1)
            {
                res.pb({key,0});
            }
            else if(freq == 2)
            {
                res.pb({key,lloc-floc});
            }
            else
            {
                freq-= 2;
                int diff = lloc-floc;
                for(int j = lloc+diff; j < n; j+= diff)
                {
                    if(v[j] != key)
                    {
                        flag = false;
                        break;
                    }
                    else
                        freq--;
                    if(freq == 0)
                    {
                        flag = true;
                        break;
                    }
                }
                if(flag && freq == 0)
                    res.pb({key,diff});
            }
           arr[key]=1;
        }
    }

    sort(res.begin(),res.end());
    cout << res.size() << el;
    for(int i = 0; i < res.size(); i++)
        cout << res[i].first << ' ' << res[i].second << el;


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