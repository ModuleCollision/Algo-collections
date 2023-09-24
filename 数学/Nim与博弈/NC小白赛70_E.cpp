#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
void kk() {
	vector<bool>vis(maxn, 0);
	vector<ll>SG(maxn, 0);
	function<void(ll)>dfs = [&](ll x) {
		vis[x] = 1;
		if (x == 1 or x == 2) {
			SG[x] = 0; return;//遇到末状态则为必输状态,SG值为0
			//SG值为正则必胜,为零则必输
		}
		set<ll>st;
		if (x & 1) {
			for (ll i = 1; i <= x / 2; i++) {
				if (not vis[i])dfs(i);
				st.insert(SG[i]);
			}
		} else {
			for (ll i = 1; i < x / 2; i++) {
				if (not vis[i])dfs(i);
				st.insert(SG[i]);
			}
		}
		for (ll i = 0;; i++) {
			if (not st.count(i)) {
				SG[x] = i; return;
			}
		}
	};
	dfs(maxn);
	for (ll i = 1; i <= 100; i++) {
		cout << i << ":" << (SG[i] == ((ll)log2(i + 1)) - 1) << endl;
	}
}
void solve() {
	//kk();//根据SG函数打个表发现规律
	ll n, m; cin >> n >> m;
	ll ans = 0;
	n = (ll)(log2(n + 1) - 1);
	m = (ll)(log2(m + 1) - 1);
	ans = ans ^ n ^ m;//求每一个位(每一个子问题)的SG函数,看亦或和
	//异或和为正则先手必胜,异或和为0则先手必输
	if (ans) {
		puts("Alice");
	} else {
		puts("Bob");
	}
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}