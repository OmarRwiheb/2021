#include<bits/stdc++.h>

using namespace std;

const int MX = 1e3 + 1;

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

struct edge{
    int to, cst;

}
vector<edge> adj[N];
int n, m;
void adjList(){
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
         // if undirected graph
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});

        /* // if directed graph
        adj[u].push_back({v, c});*/

    }
}

int adjMat[N][N];
void adjMatrix(){
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
/*     // if undirected graph        
      // if weighted
        adjMat[u][v] = c;
        adjMat[v][u] = c;

      // if unweighted
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
*/  
/*     // if directed graph        
      // if weighted
        adjMat[u][v] = c;

      // if unweighted
        adjMat[u][v] = 1;
*/
    }
}
int main() {
    Fast;

    

    
    return 0;

}
