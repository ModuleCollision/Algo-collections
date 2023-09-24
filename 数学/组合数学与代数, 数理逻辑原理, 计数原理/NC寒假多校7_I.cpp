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
		ll len = s[w[0]].size(); ll ans = 0;
		for (ll i = 0; i < (1 << len); i++) {//枚举一定长度下全部的可能串
			string tmp = "";
			for (ll j = 0; j < len; j++) {
				if ((i >> j) & 1)tmp.push_back('1');
				else tmp.push_back('0');
			}
			//判断枚举的该串是否可以匹配到至少一个串
			for (ll k = 0; k < w.size(); k++) {
				bool f = true;
				for (ll j = 0; j < len; j++) {
					if (s[w[k]][j] == '?' or s[w[k]][j] == tmp[j])continue;
					f = false; break;
				}
				if (f) {
					ans++; break;
				}
			}
		}
		return ans;
	};
	function<ll(vector<ll>)>dfs = [&](vector<ll>w) {//求并集
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
					/*如果在一个位上出现不同的0 , 1那么肯定不可能匹配, 所以分开处理*/
					if (s[v][i] == '?')mid.push_back(v);
				}
				ans = (ans % mod + dfs(l)) % mod;
				ans = (ans % mod + dfs(r)) % mod;
				ans = ((ans % mod - dfs(mid)) % mod + mod) % mod;
				return ans % mod;
			}
		}
		/*做容斥*/
		for (ll i = 1; i < (1 << w.size()); i++) {
			//把每个字符串看成一个集合, 则这里求的是组字符串交集的方案数, 状压枚举交集
			vector<bool>vis(len + 5, true); vector<ll>v;
			for (ll j = 0; j < w.size(); j++) {
				if ((i >> j) & 1) {
					v.push_back(w[j]);
				}
			}
			/*递归到底层, 这些字符串的每一位要么是 0 ? ,要么是1 ?, 可以直接容斥求并集*/
			for (auto vv : v) {
				for (ll k = 0; k < len; k++) {
					if (s[vv][k] != '?')vis[k] = 0;
				}
			}
			ll res = 1;
			for (ll s = 0; s < len; s++)if (vis[s] == 1)res = res * 2 % mod;
			if (v.size() & 1)ans = (ans % mod + res) % mod;
			else ans = ((ans - res) % mod + mod) % mod;
		}//结合容斥原理的公式
		return ans % mod;
	};
	/*function<ll(vector<ll>)>dfs = [&](vector<ll>w) {//求并集
		if (w.size() == 0)return 0ll;
		ll ret = 0; ll len = s[w[0]].size();
		for (ll i = 1; i < (1 << w.size()); i++) {
			vector<ll>v;
			for (ll j = 0; j < w.size(); j++)if ((i >> j) & 1)v.push_back(w[j]);
			ll ans = 1;
			for (ll j = 0; j < len; j++) {
				ll cnt1 = 0, cnt0 = 0, cntw = 0;
				for (auto c : v) {
					if (s[c][j] == '1')cnt1++;
					if (s[c][j] == '0')cnt0++;
					if (s[c][j] == '?')cntw++;
				}
				if (cnt1 and cnt0) {
					ans = 0; break;
				} else if (not cnt1 and not cnt0 and cntw)ans = (ans % mod * 2 % mod);
			}
			if (v.size() & 1)ret = (ret % mod + ans) % mod;
			else ret = ((ret - ans) % mod + mod) % mod;
		}
		return ret % mod;
	};*/
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