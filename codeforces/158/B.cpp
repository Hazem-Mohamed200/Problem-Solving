#include <bits/stdc++.h>
#define mod 1000000007
#define el '\n'
#define ll long long
#define ld long double
#define pb push_back   // vector & deque
#define pf push_front   // deque
#define p push   // stack & queue
#define MAX 100000000
using namespace std;
//***************** Hazem Mohamed **********************//

void zuka()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    zuka();
    int n; cin >> n;
    int res = 0;
    vector<int>v;
    int freq[5]={};
    int saver1 = 0;
    int saver2 = 0;
    int saver3 = 0;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;

        if(x == 4)
            {res++; continue;}
        else if(x == 1)
            {saver1++; freq[x]++;}
        else if(x == 2)
            {saver2++; freq[x]++;}
        else
            {saver3++; freq[x]++;}

        if(saver1 > 0 && saver3 > 0)
        {
            saver1--; saver3--;
            freq[1]--; freq[3]--;
            res++;
        }
        else if(saver2 >= 2)
        {
            saver2-=2;
            freq[2] -= 2;
            res++;
        }
    }
    for(int i = 1; i <= 4; i++)
    {
        while(freq[i] != 0)
        {
            v.pb(i);
            freq[i]--;
        }
    }
    int holder = 0;
    for(int i = 0; i < v.size();)
    {
        holder += v[i];
        if(holder < 4 && i != v.size()-1)
        {
            i++;
            continue;
        }
        else if(holder > 4)
        {
            res++;
            holder = 0;
        }
        else if(holder == 4)
        {
            res++;
            i++;
            holder = 0;
        }
        if(i == v.size()-1 && holder < 4)
        {
            res++;
            holder = 0;
            i++;
        }
    }
    cout << res;





}