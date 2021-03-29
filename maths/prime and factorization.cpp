/* some useful facts:
= 1 is not prime
= all primes except 2 are odd
= all primes greater than 3 can be written in the form 6k+/-1
= any number n can have only one primefactor greater than sqrt(n)
= the consequence for primality testing of a number n is: if we cannot find a number f less 
than or equal sqrt(n) that divedes n then n is prime */

#include<bits/stdc++.h>
using namespace std;

#define PI 3.14159265
#define sqr(x) ((x)*(x))
#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define all(v) ((v).begin()), ((v).end())
#define rev(v) ((v).rbegin()), ((v).rend())
#define rep(i, st, en) for(int i = st; i < en; i++)
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;



// all prime and factorization function that depending on sieve function
const int MAX = 1e4;
int prefix[MAX];
ll sieve_size;
bitset<10000010>bs;
vll p;
// sieve of eratosthenes function to generate all primes between 2 and n
void sieve(ll upperbound) {
    sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = false;
    for (ll i = 2; i < sieve_size; i++) {
        if (bs[i]) {
            for (ll j = i * i; j < sieve_size; j += i) bs[j] = false;
            p.push_back(i);
        }
    }
    prefix[0] = prefix[1] = 0;
    for (int i = 2; i <= MAX; i++) {
        prefix[i] = prefix[i - 1];
        if (bs[i])
            prefix[i]++;
    }
}

// generate the prime factors of n
vll primeFactors(ll n){
    vll factors;
    for(int i = 0 ; (i < (int)p.size() && (p[i] * p[i] <= n)); i++)
        while(n % p[i] == 0){ n /= p[i]; factors.push_back(p[i]);}
    if(n != 1) factors.push_back(n);
    return factors;
}

// claculate the number of the prime factors of n
ll numPF(ll n){
    int ans = 0;
    for(int i = 0 ; (i < (int)p.size() && (p[i] * p[i] <= n)); i++)
        while(n % p[i] == 0){ n /= p[i]; ans++;}
    return ans + (n != 1);
}

// calculate the number of the divisors of n 
ll numDiv(ll n){
    int ans = 1;
    for(int i = 0 ; (i < (int)p.size() && (p[i] * p[i] <= n)); i++){
        int power = 0;
        while(n % p[i] == 0){n /= p[i]; power++;}
        ans *= power + 1;
    }
    return (n != 1)? 2 * ans : ans;
}

// calculate the sum of the divisors of n
ll sumDiv(ll n){
    ll ans = 1;
    for(int i = 0 ; (i < (int)p.size() && (p[i] * p[i] <= n)); i++){
        ll multiplier = p[i], total = 1;
        while(n % p[i] == 0){
            n /= p[i];
            total += multiplier;
            multiplier *= p[i];
        }
        ans *= total;
    }
    if(n > 1) ans *= (n+1);
    return ans;
}

// calculate the sum of the prime factors of n
ll sumPF(ll n){
    ll ans = 0;
    for(int i = 0 ; (i < (int)p.size() && (p[i] * p[i] <= n)); i++){
        ll total = 0;
        while(n % p[i] == 0){
            n /= p[i];
            total += p[i];
        }
        ans += total;
    }
    if(n != 1) ans += n;
    return ans;
}

// calculate the number of different prime factors of n
ll numDiffPF(ll n){
    int ans = 0;
    for(int i = 0 ; (i < (int)p.size() && (p[i] * p[i] <= n)); i++) {
        bool f = 0;
        while (n % p[i] == 0) {
            n /= p[i];
            f = 1;
        }
        if(f)
            ans++;
    }
    return ans + (n != 1);
}

// functions that not depend on the sieve function
// check if the number is prime of not
bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; sqr(i) <= n; i = i + 6)
        if (n % i != 0 && n % (i + 2) == 0)
            return false;

    return true;
}

// generete the divisors of n
vll generateDiv(ll n){
    vll v;
    ll i;
    for(i = 1; i * i < n; i++) {
        if (n % i == 0)
            v.push_back(i), v.push_back(n / i);
    }

    if(i * i == n)
        v.push_back(n);
    return v; // not sorted
}

// generete the number of prime factors of n
vll generatePF(ll n){
    vll v;
    ll i;
    for(i = 2; i * i <= n; i++) {
        while (n % i == 0) v.push_back(i), n /= i;
    }
    if(n > 1)
        v.push_back(n);
    return v;
}

int main(){
    sieve(20);
    for(auto it: p)
        cout << it << " ";


    return 0;
}
