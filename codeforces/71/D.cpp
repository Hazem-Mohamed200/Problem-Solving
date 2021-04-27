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
string input[N][N] = {};
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
    map<pii,vector<pii>>squares;
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
                        bool s1 = true,s2 = true; //Check the validity of the two squares
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
                            squares[{i,j}].pb({si,sj});
                    }
                }
            }
        }
    }
    return squares;
}
int main()
{
    cin >> n >> m;
    set<string>cards = pre(); // All Cards
    vector<pair<string,pii>>jokers;
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
    map<pii,vector<pii>>squares = pre2();
    if(jokers.size() == 2)
    {
        int y1,y2,x1,x2;
        string j1 = "",j2 = "";
        bool done = false;
        for(auto c1:cards)
        {
            j1 = c1;
            input[jokers[0].S.F][jokers[0].S.S] = c1;
            for(auto c2:cards)
            {
                if(c2 == c1)
                    continue;
                j2 = c2;
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
                            y1 = s1i, x1 = s1j;
                            y2 = s2i, x2 = s2j;
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
        if(done)
        {
            if(jokers[0].F == "J2")
                swap(j1,j2);

            cout << "Solution exists.\n";
            cout << "Replace J1 with " << j1 << " and J2 with " << j2 << ".\n";
            cout << "Put the first square to (" << y1 << ", " << x1 << ").\n";
            cout << "Put the second square to (" << y2 << ", " << x2 << ").\n";
        }
        else
            cout << "No solution.";
    }
    else if(jokers.size() == 1)
    {
        int y1,y2,x1,x2;
        string j1 = "";
        bool done = false;
        for(auto c1:cards)
        {
            j1 = c1;
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
                        y1 = s1i, x1 = s1j;
                        y2 = s2i, x2 = s2j;
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
        {
            cout << "Solution exists.\n";
            cout << "Replace " << jokers[0].F << " with " << j1 <<".\n";
            cout << "Put the first square to (" << y1 << ", " << x1 << ").\n";
            cout << "Put the second square to (" << y2 << ", " << x2 << ").\n";
        }
        else
            cout << "No solution.";
    }
    else
    {
        if(squares.size())
        {
            int y1 = squares.begin()->F.F, x1 = squares.begin()->F.S;
            int y2 = squares.begin()->S[0].F, x2 = squares.begin()->S[0].S;
            cout << "Solution exists.\n";
            cout << "There are no jokers.\n";
            cout << "Put the first square to (" << y1 << ", " << x1 << ").\n";
            cout << "Put the second square to (" << y2 << ", " << x2 << ").\n";
        }
        else
            cout << "No solution.";
    }
}