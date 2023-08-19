#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e4 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
/*根号分治 + 容斥*/
void solve() {
	ll n; cin >> n;
	vector<string>s(n + 5); vector<vector<ll>>t(405);
	for (ll i = 1; i <= n; i++) {
		std::cin >> s[i];
		t[s[i].size()].push_back(i);
	}
	auto getsum = [&](vector<ll>w) {
		if (not w.size())return 0ll;
		ll len = s[w[0]].size();
		ll ans = 0;
		for (ll i = 1; i < (1 << w.size()); i++) {
			vector<ll>vv;//枚举状态
			for (ll j = 0; j < w.size(); j++) {
				if ((i >> j) & 1)vv.push_back(w[j]);
			}
			bool f = true; string str = s[vv[0]];
			for (ll j = 1; j < vv.size(); j++) {
				for (ll k = 0; k < len; k++) {
					if (str[k] == '?')str[k] = s[vv[j]][k];
					else {
						if (s[vv[j]][k] == '?')continue;
						if (s[vv[j]][k] != str[k]) {
							f = false; break;
						}
					}
				}
				if (not f)break;
			}
			/*做容斥*/
			if (f) {
				ll res = 1; //求枚举到某一个状态下的交集
				for (ll j = 0; j < len; j++) {
					if (str[j] == '?')res = res * 2 % mod;
				}
				if (vv.size() & 1)ans = (ans + res) % mod;
				else ans = ((ans - res) % mod + mod) % mod;

			}
		}
		return ans;
	};
	function<ll(vector<ll>)>dfs = [&](vector<ll>w) {
		if (w.size() == 0)return 0ll;
		vector<ll>x;
		for (auto v : w)x.push_back(v);
		ll ans = 0; ll len = s[w[0]].size();
		for (ll i = 0; i < len; i++) {
			ll cnt0 = 0, cnt1 = 0;
			for (auto v : x) {
				if (s[v][i] == '0')cnt0++;
				else if (s[v][i] == '1')cnt1++;
			}
			if (cnt0 and cnt1) {
				vector<ll>l, r, mid;
				for (auto v : x) {
					if (s[v][i] == '0' or s[v][i] == '?')l.push_back(v);
					if (s[v][i] == '1' or s[v][i] == '?')r.push_back(v);
					if (s[v][i] == '?')mid.push_back(v);
				}
				ans = (ans % mod + dfs(l)) % mod;
				ans = (ans % mod + dfs(r)) % mod;
				ans = ((ans % mod - dfs(mid)) % mod + mod) % mod;
				return ans % mod;
			}
		}
		for (ll i = 1; i < (1 << w.size()); i++) {
			vector<bool>vis(len + 5, true); vector<ll>v;
			for (ll j = 0; j < w.size(); j++) {
				if ((i >> j) & 1) {
					v.push_back(w[j]);
				}
			}
			for (auto vv : v) {
				for (ll k = 0; k < len; k++) {
					if (s[vv][k] != '?')vis[k] = 0;
				}
			}
			ll res = 1;
			for (ll s = 0; s < len; s++)if (vis[s] == 1)res = res * 2 % mod;
			if (v.size() & 1)ans = (ans % mod + res) % mod;
			else ans = ((ans - res) % mod + mod) % mod;
		}
		return ans % mod;
	};
	ll p = 0;
	for (ll i = 1; i <= 400; i++) {
		if (i <= 20)p = (p % mod + getsum(t[i])) % mod;
		else p = (p % mod + dfs(t[i])) % mod;
	}
	cout << p % mod << endl;
}
signed main() {

	solve();
}