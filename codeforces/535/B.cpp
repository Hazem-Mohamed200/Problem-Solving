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
const ll MAX = 100000; const ll mod = 1000000007;
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
int fact(int n)
{
    if(n == 0)
        return 1;
    return n * fact(n-1);
}
int fib(int n)
{
    // if first = 0 --> return 1-n
    // if first = 1 --> return n
    if(n < 2)
        return n;
    return fib(n-1)+fib(n-2);
}
vec(pii)items = {{4,1},{4,1},{4,10}};
int knapsack(int ind, int curCapacity)
{
    // base case a5d kol el items ya3ny
    if(ind == items.size())
        return 0;

    int leave = knapsack(ind+1,curCapacity); // path enk tsibha w tm4y
    if(items[ind].S <= curCapacity)
        return max(leave, items[ind].F + knapsack(ind+1,curCapacity-items[ind].S));
    // anhy a7sn? path tsibha w tm4y wla path ta5odha??
    else
        return leave; // 3afia hatsibha w tm4y
}
ll n;
ll fun(ll lucky,ll index)
{
    // base case
    if(lucky == n)
        return index;
    else if(lucky > n)
        return -1; // 34an a5od ely ablo mnel max dah
    //transition
    return max(fun(lucky*10+7,index*2+2),fun(lucky*10+4,index*2+1));
}
int main()
{
    zuka();
    cin >> n;
    cout << fun(0,0);
}