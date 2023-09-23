/*先序遍历序列(dfn)序列 遵从 rot + lch + rch*/
/*中序遍历序列遵从 lch + rot + rch*/
/*后序遍历序列遵从 lch + rch + rot*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e6 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll dfn[maxn], siz[maxn], n;
vector<pair<ll, ll>>ans;
void solve() {
	std::cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> dfn[i];
	}
	for (ll i = 1; i <= n; i++) {
		std::cin >> siz[i];
	}
	function<void(ll)>dfs = [&](ll id) {
		ll cur = dfn[id], k = id + 1, t = siz[cur];
		if (t == 1) {
			return;
		}
		t -= 1;
		while (t and k <= n) {
			t -= siz[dfn[k]]; dfs(k);
			ll a = max(cur, dfn[k]), b = min(cur, dfn[k]);
			ans.push_back({b, a});
			k += siz[dfn[k]];
		}
	};
	//根据一颗树的dfn序和每个子树的siz值唯一确定一颗树
	dfs(1);
	std::sort(ans.begin(), ans.end(), [&](pair<ll, ll>a, pair<ll, ll>b)->bool{
		return a.first == b.first ? a.second < b.second : a.first < b.first;
	});
	for (auto [x, y] : ans) {
		cout << x << " " << y << "\n";
	}
}
/*Fuck you,bitch!*/
signed main() {
	solve();
}

