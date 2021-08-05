#include<bits/stdc++.h>

using namespace std;

const int N = 1e4 + 1;

#define PI 3.14159265
#define sqr(x) ((x)*(x))
#define pr pair<ll, ll>
#define vi vector<ll>
#define vll vector<long long>
#define vp vector<pair<int, int>>
#define vull vector<unsigned long long>
#define all(v) ((v).begin()), ((v).end())
#define rev(v) ((v).rbegin()), ((v).rend())
#define rep(i, st, en) for(ll i = st; i < en; i++)
#define Fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }


bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first == b.first)
        return a.second > b.second;
    else 
        return a.first < b.first;

}

template<typename T>
void input(vector<T>& v){ for(auto& it : v) cin >> it; }

int binPow(ll b, ll p) {
    if (p == 0) return 1;
    ll sq = binPow(b, p / 2);
    sq *= sq;

    if (p & 1)
        sq *= b;

    return sq;
}

vector<int> adj[N];
int n, m;
int vis[N];
int dfs(int u){
    vis[u] = 1;
    int mycnt = 1;
    // loop over my neighbors
    for(int v : adj[u]){
        if(vis[v] == 1)continue;
        mycnt += dfs(v);
    }
    return mycnt;
}

int main() {
    Fast;

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int v, u;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfs(1);
    return 0;

}
