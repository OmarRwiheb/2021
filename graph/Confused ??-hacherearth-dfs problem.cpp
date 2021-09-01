#include<bits/stdc++.h>

using namespace std;

const int MX = 1e6 + 1;

#define PI 3.14159265
#define sqr(x) ((x)*(x))
#define pr pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define all(v) ((v).begin()), ((v).end())
#define rev(v) ((v).rbegin()), ((v).rend())
#define rep(i, st, en) for(int i = st; i < en; i++)
#define Fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }


bool sortbysec(const pair<string, string> &a, const pair<string, string> &b) {
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;

}

template<typename T>
void input(vector<T>& v){ for(auto& it : v) cin >> it; }

ll binPow(ll b, ll p) {
    if (p == 0) return 1;
    ll sq = binPow(b, p / 2);
    sq *= sq;

    if (p & 1)
        sq *= b;

    return sq;
}

vector<vector<int>>adj;
map<int, int>mp;
vi vis;
int pie;
vi pieMate;
void dfs(int u){
    vis[u] = 1;
    if(mp[u])pie = mp[u];
    pieMate.push_back(u);
    for(int neig: adj[u]){
        if(vis[neig])continue;
        dfs(neig);
    }
}
int main() {
    Fast;

    int n, m, q;
    cin >> n >> m >> q;
    vi pies(m);
    input(pies);
    adj.resize(n);
    vis.resize(n);
    map<int, int>piesTaken;
    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        u--, v--;
        if(t == 2) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else{
            mp[u] = v;
            piesTaken[v]++;
        }
    }
    vector<double> ans(n);
    for(int i = 0; i < n; i++){
        if(!vis[i]) {
            dfs(i);
            for(int mate: pieMate){
                ans[mate] = pies[pie] / (double)pieMate.size();
            }
            pie = 0;
            pieMate.clear();
        }
    }
    cout << piesTaken.size() << "\n";
    for(auto it: ans){
        cout << fixed << setprecision(6) << it << "\n";
    }
    return 0;
}
