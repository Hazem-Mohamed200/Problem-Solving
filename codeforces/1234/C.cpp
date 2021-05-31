#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define F first
#define S second
#define pb push_back
#define ll long long
#define Zuka  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "wt", stdout);

const ll INF = LONG_LONG_MAX;
const ll N = 2e5+5; const ll mod = 1e9+7;


char arr[2][N];
void testCase()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < n; i++)
    {
        if(s1[i] == '1' || s1[i] == '2')
            s1[i] = '0';
        else
            s1[i] = '1';

        if(s2[i] == '1' || s2[i] == '2')
            s2[i] = '0';
        else
            s2[i] = '1';

        arr[0][i] = s1[i];
        arr[1][i] = s2[i];
    }
    // L shaped '1'
    // Bar shaped '0'

    int row = 0, col = 0;
    bool can = true;
    for(col = 0; col < n; col++)
    {
        if(arr[row][col] == '1')
        {
            if(row == 0 && arr[1][col] != '1')
                can = false;
            else if(row == 0)
                row++;
            else if(row == 1 && arr[0][col] != '1')
                can = false;
            else if(row == 1)
                row--;
        }
        if(!can)
            break;
    }
    if(can && col == n && row == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    Zuka
    int t = 1;
    cin >> t;
    while(t--)
        testCase();
}