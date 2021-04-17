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
const ll MAX = 4; const ll mod = 1000000007;
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
    string s; cin >> s;
    int ctr = 0;
    int letters = 0;
    set<int>pos;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '@')
        {
            ctr++;
            pos.insert(i);
        }
    }
    letters = s.length()-ctr;
    if(letters < ctr*2 || ctr == 0)
        cout << "No solution";
    else
    {
        string ans = "";
        int stop = 0;
        bool done = false;
        while(true)
        {
            for(int i = stop; i < s.length(); i++)
            {
                ans += s[i];
                if(s[i] == '@')
                {
                    auto it = pos.upper_bound(i);
                    if(it != pos.end())
                    {
                        int j;
                        for(j = i+1; j < *it-1; j++)
                            ans+=s[j];
                        ans+=',';
                        stop = j;
                        break;
                    }
                    else
                    {
                        for(int k = i+1; k < s.length(); k++)
                        {
                            ans+=s[k];
                        }
                        done = true;
                        break;
                    }
                }
            }
            if(done)
                break;
        }
        //cout << ans;
        for(int i = 0; i < ans.length(); i++)
        {
            if(ans[i] == '@')
            {
                if(i > 0 && ans[i-1] != ',' && ans[i-1] != '@' && i < ans.length()-1 && ans[i+1] != ',' && ans[i+1] != '@')
                    continue;
                else
                {
                    cout << "No solution";
                    return 0;
                }
            }
        }
        cout << ans;
    }

}