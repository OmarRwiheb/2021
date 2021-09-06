#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<ll>> adj;
vector<ll> vis;
int val = 1;

void dfs(int u){
		vis[u] = val;
		for(auto neig: adj[u]){
			if(vis[neig] == val)continue;
			dfs(neig);
		}
}

int main(){

	ll n, q, t;
	cin >> n >> q >> t;
	ll lastans = 0;
	vis.resize(n);
	adj.resize(n);
	vis[0] = val;
	while(q--){
		ll que;
		cin >> que;
		if(que == 2){
			ll a;
			cin >> a;
			a = (a ^ (t * lastans)) % n;
			if(vis[a]){
				cout << a + 1 << "\n";
				lastans = a + 1;
			}
			else{
				cout << "0\n";
				lastans = 0;
			}
		}
		else{
			ll a, b;
			cin >> a >> b;
			a = (a ^ (t * lastans)) % n;
			b = (b ^ (t * lastans)) % n;
			adj[a].push_back(b);
			if(vis[a]){
				vis[b] = val;
				dfs(b);
			}
		}
	}	

	return 0;
}
