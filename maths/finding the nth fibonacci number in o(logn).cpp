// calculate the nth fibonacci number using matrix exponantial method
#include<bits/stdc++.h>
using namespace std;

#define PI 3.14159265
#define sqr(x) ((x)*(x))
#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define all(v) ((v).begin()), ((v).end())
#define rev(v) ((v).rbegin()), ((v).rend())
#define rep(i, n) for(size_t i = 0; i < n; i++)

const int MAX = 1e3+1;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

void Fib(int n){
    int prev[] = {0, 1};
    for(int i = 2; i<=n; i++){
        prev[i&1] += prev[(i-1)&1];
    }
}

void multiply(ll F[2][2], ll M[2][2])
{
    ll x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    ll y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    ll z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    ll w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(ll F[2][2], int n)
{
    if(n == 0 || n == 1)
        return;
    ll M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

ll fib(int n)
{
    ll F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);

    return F[0][0];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}
