/*后效性dp ---> 由当前枚举到的状态去维护 待转移的 未维护到的状态(后置状态)*/
/*dp 状态可以看作是DAG图, 所以可以记录访问状态进行记忆化搜索*/
/*记忆化必须满足无后效性*/

#include<bits/extc++.h>

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;

constexpr i64 mod = 1e9 + 7;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

i64 N;
void solve() {
	vector<string>k(5);
	i64 n; std::cin >> n;
	std::map<array<i64, 4>, i64>dp;
	vector<i64>s(3, 0);
	std::map<char, i64>st;
	st['w'] = 0; st['i'] = 1; st['n'] = 2;
	auto inv = [&](i64 x) {
		i64 b = mod - 2; i64 ret = 1;
		while (b) {
			if (b & 1)ret = ret * x % mod;
			x = x * x % mod;
			b >>= 1;
		}
		return ret % mod;
	};
	auto sorted = [&](array<i64, 3>a) {
		sort(a.begin(), a.end());
		return a;
	};
	auto get1 = [&](i64 i, i64 j, i64 k) {
		auto [ii, jj, kk] = sorted({i, j, k});
		return ii + jj * 3 + kk * 9;
	};
	auto get = [&](array<i64, 3>a) {
		auto [i, j, k] = sorted(a);
		return get1(i, j, k);
	};
	auto get3 = [&](i64 x) {
		i64 k = x % 3;
		x /= 3;
		int j = x % 3;
		x /= 3;
		int i = x;
		return sorted({i, j, k});
	};
	vector<i64>win(27); vector<i64>spec(27, -1);
	for (i64 i = 0; i < 3; i++) {
		for (i64 j = i; j < 3; j++) {
			for (i64 k = j; k < 3; k++) {
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
	function<i64(i64, i64, i64, i64)>dfs = [&](i64 m, i64 s0, i64 s1, i64 s2) {
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
					i64 v = dfs(m + 1, get(ns0), get(ns1), get(ns2)) % mod * inv(9) % mod;
					dp[ {m, s0, s1, s2}] = (dp[ {m, s0, s1, s2}] % mod + v) % mod;
				} else {
					for (i64 k = 0; k < 3; k++) {
						auto ns0 = get3(s0);
						auto ns1 = get3(s1);
						auto ns2 = get3(s2);
						swap(ns0[i], ns1[j]);
						swap(ns0[i], ns2[k]);
						i64 v = dfs(m + 1, get(ns0), get(ns1), get(ns2)) % mod * inv(27) % mod;
						dp[ {m, s0, s1, s2}] = (dp[ {m, s0, s1, s2}] % mod + v) % mod;
					}
				}
			}
		}
		return dp[ {m, s0, s1, s2}];//返回这个节点的值
	};
	for (i64 i = 0; i < 3; i++) {
		string t; std::cin >> t;
		s[i] = get1(st[t[0]], st[t[1]], st[t[2]]);
	}
	cout << dfs(1, s[1], s[2], s[0]) << endl;
}
signed main() {
	solve();
}