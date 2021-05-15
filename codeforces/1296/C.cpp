#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define F first
#define S second
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 45; const ll mod = 1e9+7;

int main()
{
    Zuka
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        int posx = 0, posy = 0;
        map< pair<int, int>, vector<int> > pos;
        pos[{0,0}].push_back(0);
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'U')
            {
                posy++;
                pos[{posx, posy}].push_back(i+1);
            }
            else if(s[i] == 'D')
            {
                posy--;
                pos[{posx, posy}].push_back(i+1);
            }
            else if(s[i] == 'L')
            {
                posx--;
                pos[{posx, posy}].push_back(i+1);
            }
            else if(s[i] == 'R')
            {
                posx++;
                pos[{posx, posy}].push_back(i+1);
            }
        }
        int ans = 1e9, l = -1, r = -1;
        for(auto i:pos)
        {
            if(i.S.size() > 1)
            {
                for(int j = 1; j < i.S.size(); j++)
                {
                    if(i.S[j] - i.S[j-1] + 1 < ans)
                        ans = i.S[j] - i.S[j-1] , l = i.S[j-1] + 1, r = i.S[j];
                }
            }
        }
        if(ans == (int)1e9)
            cout << -1 << el;
        else
            cout << l << ' ' << r << el;
    }
}