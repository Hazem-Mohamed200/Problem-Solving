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
const ll mod = 1000000007;
const ll MAX = 1000005;
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
int main()
{
    zuka();
    int t; cin >> t;
    while(t--)
    {
        int n,l,r,s;
        cin >> n >> l >> r >> s;
        int nums = r-l+1;
        vec(int)v,hld;
        multiset<int>ms,perm;
        int ctr = 0;
        int sum = 0;
        for(int i = n; i >= 1; i--)
        {
            v.pb(i);
            perm.insert(i);
            if(ctr < nums)
            {
                hld.pb(i);
                ms.insert(i);
                sum+=i;
            }
            ctr++;
        }
        if(sum < s)
        {
            cout << -1 << el;
            continue;
        }
        else
        {
            int sumh = sum;
            int limit = 1;
            bool done = false;
            for(int i = 0; i < nums; i++)
            {
                sort(all(hld));
                if(sumh == s)
                {
                    done = true;
                    break;
                }
                while(hld[i] > limit)
                {
                    if(sumh == s)
                    {
                        done = true;
                        break;
                    }
                    ms.erase(ms.find(hld[i]));
                    hld[i]--;
                    sumh--;
                    ms.insert(hld[i]);
                    if(sumh == s)
                    {
                        done = true;
                        break;
                    }
                    while(ms.count(hld[i]) > 1 && hld[i] > limit)
                    {
                        ms.erase(ms.find(hld[i]));
                        hld[i]--;
                        sumh--;
                        ms.insert(hld[i]);
                        if(sumh == s)
                        {
                            done = true;
                            break;
                        }
                    }
                }
                limit++;
                if(done)
                    break;
            }
            if(!done)
            {
                cout << -1 << el;
                continue;
            }
            else
            {
                int j = 0;
                for(auto i:ms)
                    perm.erase(i);
                for(int i = 1; i <= n; i++)
                {
                    if(i < l)
                    {
                        cout << *perm.begin() << ' ';
                        perm.erase(perm.begin());
                    }
                    else if(i >= l && i <= r)
                    {
                        cout << *ms.begin() << ' ';
                        ms.erase(ms.begin());
                    }
                    else
                    {
                        cout << *perm.begin() << ' ';
                        perm.erase(perm.begin());
                    }
                }
                cout << el;
            }
        }
    }
}
