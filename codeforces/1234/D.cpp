#include <bits/stdc++.h>
#define mod 1000000007
#define el '\n'
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pff pair<float,float>
#define vec(int) vector<int>
#define pb push_back
#define pf push_front
#define mms(v,i) memset(v, i, sizeof v)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define MAX 200005
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
    vector<set<int>>freq(26);
    for(int i = 0; i < s.length(); i++)
        freq[s[i]-'a'].insert(i);
    int q; cin >> q;
    while(q--)
    {
        int t; cin >> t;
        if(t == 1)
        {
            int p; cin >> p;
            char c; cin >> c;
            // swap the letter location
            // mn el 7rf el 2adim wadiiih ll 7rf el gdid
            freq[s[p-1]-'a'].erase(p-1);
            s[p-1] = c;
            freq[s[p-1]-'a'].insert(p-1);
        }
        else
        {
            int l,r; cin >> l >> r;
            int ctr = 0;
            for(int i = 0; i < 26; i++)
            {
                auto it = freq[i].lower_bound(l-1); // l mawgoda f ay 7rf
                if(it != freq[i].end() && *it <= r-1)//in range ya3ny
                    ctr++;
            }
            cout << ctr << el;
        }
    }
}