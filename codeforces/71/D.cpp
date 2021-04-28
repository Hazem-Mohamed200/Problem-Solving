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
const ll N = 20; const ll mod = 1000000007;
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
int n,m;
int ansy1,ansy2,ansx1,ansx2;
string joker1,joker2;
string input[N][N] = {};
vector<pair<string,pii>>jokers;
map<pii,vector<pii>>squares;
bool overlap(int i1, int j1, int i2, int j2)
{
    if (i2 > i1 + 2 || i1 > i2 + 2)
        return false;
    if (j2 > j1 + 2 || j1 > j2 + 2)
        return false;
    return true;
}
set<string>pre()
{
    char suits[4] = {'C','D','H','S'};
    char ranks[13] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
    set<string>cards;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            string c = "";
            c = ranks[j];
            c += suits[i];
            cards.insert(c);
        }
    }
    return cards;
}
map<pii,vector<pii>>pre2()
{
    map<pii,vector<pii>>group;
    for(int i = 1; i <= n-2; i++)
    {
        for(int j = 1; j <= m-2; j++)
        {
            for(int si = 1; si <= n-2; si++)
            {
                for(int sj = 1; sj <= m-2; sj++)
                {
                    if(!overlap(i,j,si,sj) && si + 2 <= n && sj + 2 <= m)
                    {
                        //First Square
                        map<char,int>freq1,freq2;
                        bool s1 = true,s2 = true; //Check the validity of the two group
                        for(int y = i; y <= i + 2; y++)
                        {
                            for(int x = j; x <= j + 2; x++)
                            {
                                if(input[y][x] != "J1" && input[y][x] != "J2")
                                    freq1[input[y][x][0]]++;
                            }
                        }
                        //Second Square
                        for(int y = si; y <= si + 2; y++)
                        {
                            for(int x = sj; x <= sj + 2; x++)
                            {
                                if(input[y][x] != "J1" && input[y][x] != "J2")
                                    freq2[input[y][x][0]]++;
                            }
                        }
                        for(auto x:freq1)
                        {
                            if(x.S > 1)
                            {s1 = false;break;}
                        }
                        for(auto x:freq2)
                        {
                            if(x.S > 1)
                            {s2 = false;break;}
                        }
                        if(s1 && s2)
                            group[{i, j}].pb({si, sj});
                    }
                }
            }
        }
    }
    return group;
}
void output(int j,bool can)
{
    if(can)
    {
        cout << "Solution exists.\n";
        if(j == 2)
        {
            if(jokers[0].F == "J2")
                swap(joker1,joker2);
            cout << "Replace J1 with " << joker1 << " and J2 with " << joker2 << ".\n";
        }
        else if(j == 1)
            cout << "Replace " << jokers[0].F << " with " << joker1 <<".\n";
        else
            cout << "There are no jokers.\n";
        cout << "Put the first square to (" << ansy1 << ", " << ansx1 << ").\n";
        cout << "Put the second square to (" << ansy2 << ", " << ansx2 << ").\n";
    }
    else
        cout << "No solution.";
}
int main()
{
    cin >> n >> m;
    set<string>cards = pre(); // All Cards
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> input[i][j];
            cards.erase(input[i][j]);
            if(input[i][j] == "J1" || input[i][j] == "J2")
                jokers.pb({input[i][j],{i,j}});
        }
    }
    squares = pre2();
    if(jokers.size() == 2)
    {
        bool done = false;
        for(auto c1:cards)
        {
            joker1 = c1;
            input[jokers[0].S.F][jokers[0].S.S] = c1;
            for(auto c2:cards)
            {
                if(c2 == c1)
                    continue;
                joker2 = c2;
                input[jokers[1].S.F][jokers[1].S.S] = c2;
                for(auto i = squares.begin(); i != squares.end(); i++)
                {
                    for(int j = 0; j < i->second.size(); j++)
                    {
                        int s1i = i->F.F, s1j = i->F.S;
                        int s2i = i->S[j].F, s2j = i->S[j].S;
                        map<char,int>freq1,freq2;
                        bool s1 = true,s2 = true;

                        for(int y = s1i; y <= s1i + 2; y++)
                            for(int x = s1j; x <= s1j + 2; x++)
                                freq1[input[y][x][0]]++;

                        for(int y = s2i; y <= s2i + 2; y++)
                            for(int x = s2j; x <= s2j + 2; x++)
                                freq2[input[y][x][0]]++;
                        for(auto x:freq1)
                        {
                            if(x.S > 1)
                            {s1 = false;break;}
                        }
                        for(auto x:freq2)
                        {
                            if(x.S > 1)
                            {s2 = false;break;}
                        }
                        if(s1 && s2)
                        {
                            done = true;
                            ansy1 = s1i, ansx1 = s1j;
                            ansy2 = s2i, ansx2 = s2j;
                            break;
                        }
                    }
                    if(done)
                        break;
                }
                if(done)
                    break;
            }
            if(done)
                break;
        }
        output(2,done);
    }
    else if(jokers.size() == 1)
    {
        bool done = false;
        for(auto c1:cards)
        {
            joker1 = c1;
            input[jokers[0].S.F][jokers[0].S.S] = c1;
            for(auto i = squares.begin(); i != squares.end(); i++)
            {
                for(int j = 0; j < i->second.size(); j++)
                {
                    int s1i = i->F.F, s1j = i->F.S;
                    int s2i = i->S[j].F, s2j = i->S[j].S;
                    map<char,int>freq1,freq2;
                    bool s1 = true,s2 = true;

                    for(int y = s1i; y <= s1i + 2; y++)
                        for(int x = s1j; x <= s1j + 2; x++)
                            freq1[input[y][x][0]]++;

                    for(int y = s2i; y <= s2i + 2; y++)
                        for(int x = s2j; x <= s2j + 2; x++)
                            freq2[input[y][x][0]]++;

                    for(auto x:freq1)
                    {
                        if(x.S > 1)
                        {s1 = false;break;}
                    }
                    for(auto x:freq2)
                    {
                        if(x.S > 1)
                        {s2 = false;break;}
                    }
                    if(s1 && s2)
                    {
                        done = true;
                        ansy1 = s1i, ansx1 = s1j;
                        ansy2 = s2i, ansx2 = s2j;
                        break;
                    }

                }
                if(done)
                    break;
            }
            if(done)
                break;
        }
        output(1,done);
    }
    else
    {
        if(squares.size())
        {
            ansy1 = squares.begin()->F.F, ansx1 = squares.begin()->F.S;
            ansy2 = squares.begin()->S[0].F, ansx2 = squares.begin()->S[0].S;
        }
        output(0,squares.size());
    }

}