#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
vector<ll>tr[maxn]; bool vis[maxn];
ll N, M, S, K = 1e6;
void solve() {
	/*典型的路径搜索题,按照枚举的思路dfs搜索即可*/
	function<void(ll, ll)>dfs = [&](ll u, ll fa) {
		S++;
		if (S > K)return;
		for (auto v : tr[u]) {
			if (v == fa or vis[v])continue;
			if (S > K)return;//注意按照题意剪枝
			vis[v] = 1;
			dfs(v, u);
			vis[v] = 0;
		}
	};
	std::cin >> N >> M;
	while (M--) {
		ll u, v; std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	vis[1] = 1;
	dfs(1, 0);
	cout << min(S, K) << endl;
}
signed main() {
	solve();
}