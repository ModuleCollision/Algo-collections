/*后效性dp ---> 由当前枚举到的状态去维护 待转移的 未维护到的状态(后置状态)*/
/*dp 状态可以看作是DAG图, 所以可以记录访问状态进行记忆化搜索*/
/*记忆化必须满足无后效性*/

#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll N;
void solve() {
	vector<string>k(5);
	ll n; std::cin >> n;
	std::map<array<ll, 4>, ll>dp;
	vector<ll>s(3, 0);
	std::map<char, ll>st;
	st['w'] = 0; st['i'] = 1; st['n'] = 2;
	auto inv = [&](ll x) {
		ll b = mod - 2; ll ret = 1;
		while (b) {
			if (b & 1)ret = ret * x % mod;
			x = x * x % mod;
			b >>= 1;
		}
		return ret % mod;
	};
	auto sorted = [&](array<ll, 3>a) {
		sort(a.begin(), a.end());
		return a;
	};
	auto get1 = [&](ll i, ll j, ll k) {
		auto [ii, jj, kk] = sorted({i, j, k});
		return ii + jj * 3 + kk * 9;
	};
	auto get = [&](array<ll, 3>a) {
		auto [i, j, k] = sorted(a);
		return get1(i, j, k);
	};
	auto get3 = [&](ll x) {
		ll k = x % 3;
		x /= 3;
		int j = x % 3;
		x /= 3;
		int i = x;
		return sorted({i, j, k});
	};
	vector<ll>win(27); vector<ll>spec(27, -1);
	for (ll i = 0; i < 3; i++) {
		for (ll j = i; j < 3; j++) {
			for (ll k = j; k < 3; k++) {
				if (get1(i, j, k) == 21)win[get1(i, j, k)] = 1;
				if (i == j and i != k) {
					spec[get1(i, j, k)] = 1;
				} else if (i != j and j == k) {
					spec[get1(i, j, k)] = 1;
				}
			}
		}
	}
	/*概率dp逆推的结果是一个值,顺推的结果是一堆dp值相加*/
	/*这里采用逆推*/
	function<ll(ll, ll, ll, ll)>dfs = [&](ll m, ll s0, ll s1, ll s2) {
		if (win[s2])return dp[ {m, s0, s1, s2}] = 1;//赢了
		if (m == n + 1)return dp[ {m, s0, s1, s2}] = 0;//m局未决出胜负
		if ((win[s0] or win[s1]) and not win[s2])return dp[ {m, s0, s1, s2}] = 0;//记忆化搜索需要将所有末状态(概率为1赢或者输)的状态初始化
		if (dp.count({m, s0, s1, s2}))return dp[ {m, s0, s1, s2}];//访问过的节点直接返回
		dp[ {m, s0, s1, s2}] = 0;//初始化
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (spec[s2] != -1) {//只有9种可能的转移方式
					auto ns0 = get3(s0);
					auto ns1 = get3(s1);
					auto ns2 = get3(s2);
					swap(ns0[i], ns1[j]);
					swap(ns0[i], ns2[1]);
					ll v = dfs(m + 1, get(ns0), get(ns1), get(ns2)) % mod * inv(9) % mod;
					dp[ {m, s0, s1, s2}] = (dp[ {m, s0, s1, s2}] % mod + v) % mod;
				} else {
					for (ll k = 0; k < 3; k++) {
						auto ns0 = get3(s0);
						auto ns1 = get3(s1);
						auto ns2 = get3(s2);
						swap(ns0[i], ns1[j]);
						swap(ns0[i], ns2[k]);
						ll v = dfs(m + 1, get(ns0), get(ns1), get(ns2)) % mod * inv(27) % mod;
						dp[ {m, s0, s1, s2}] = (dp[ {m, s0, s1, s2}] % mod + v) % mod;
					}
				}
			}
		}
		return dp[ {m, s0, s1, s2}];//返回这个节点的值
	};
	for (ll i = 0; i < 3; i++) {
		string t; std::cin >> t;
		s[i] = get1(st[t[0]], st[t[1]], st[t[2]]);
	}
	cout << dfs(1, s[1], s[2], s[0]) << endl;
}
signed main() {
	solve();
}