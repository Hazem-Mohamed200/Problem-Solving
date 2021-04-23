#include <bits/stdc++.h>
#define mod 1000000007
#define el '\n'
#define ll long long
#define ld long double
#define pb push_back   // vector & deque
#define pf push_front   // deque
#define p push   // stack & queue
#define MAX 200005
using namespace std;
//***************** Hazem Mohamed **********************//

void zuka()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool isprime(ll n)
{
    if(n==1)return true;
    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}
ll __lcm(ll a, ll b)
{
    ll lcm = ((a*b)/(__gcd(a,b)));
    return lcm;
}
ll factorial(ll a)
{
    ll fact = 1;
    while(a > 0)
    {
        fact*=a;
        a--;
    }
    return fact;
}
int main()
{
    zuka();
    ll a,b;
    cin >> a >> b;
    if(max(a,b) <= 12)
        cout << __gcd(factorial(a),factorial(b));
    else
        cout << factorial(min(a,b));
}