#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

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

map<char, vector<char>>adj;
map<char, int>vis;
vector<pair<char, char>>couple;
int idx = 0;
map<char, int>taken;
vector<char> m;
vector<char> f;

void dfs(char u){
    vis[u] = 1;
    for(auto& it: adj[u]){
        if(!taken[it] && adj[it].back() == u) {
            couple.push_back({u, it}); taken[it] = 1;
            while(vis[m[idx]])idx++;
            dfs(m[idx]);
        }
        else if(!taken[it] && adj[it].back() != u){
            if(adj[adj[it].back()][0] == it) {
                couple.push_back({adj[it].back(), it}); taken[it] = 1;
                vis[adj[it].back()] = 1;
            }
            if(adj[adj[it].back()][0] != it) {
                couple.push_back({u, it}); taken[it] = 1;
                while(vis[m[idx]])idx++;
                dfs(m[idx]);
            }
        }
    }
}

int main() {
    Fast;

    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        m.resize(n);
        f.resize(n);
        input(m);
        input(f);
        for(int i = 0; i < 2 * n; i++){
            string s;
            cin >> s;
            for(int j = 2; j < s.size(); j++){
                adj[s[0]].push_back(s[j]);
            }
            if(i >= 3)reverse(all(adj[s[0]]));
        }
        dfs(m[idx]);
        sort(all(couple));
        for(auto it: couple)
            cout << it.first << " " << it.second << "\n";
        adj.clear();
        vis.clear();
        couple.clear();
        idx = 0;
        taken.clear();
        cout << "\n";
    }

    return 0;
}
