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

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
	i64 n; std::cin >> n;
	vector<i64>d(n + 5, 0);//出度
	vector<i64>k(n + 5, 0);//入度
	vector<string>s(n + 5);
	for (i64 i = 1; i <= n; i++) {
		std::cin >> s[i];
		s[i] = " " + s[i];
	}
	vector<vector<i64>>tr(n + 5);
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 1; j <= n; j++) {
			if (s[i][j] == '1') {
				tr[j].push_back(i); d[i]++; k[j]++;
			}
		}
	}
	//出度为0表示是最小的真子集
	vector<set<i64>>vv(n + 5);
	for (i64 i = 1; i <= n; i++)vv[i].insert(i);
	vector<bool>vis(n + 5, 0);
	function<void(i64)>dfs = [&](i64 u) {
		vis[u] = 1;
		if (not k[u]) {
			return;
		}
		for (auto v : tr[u]) {
			if (not vis[v])
				dfs(v);
			for (auto c : vv[v]) {
				vv[u].insert(c);
			}
		}
	};
	for (i64 i = 1; i <= n; i++) {
		if (not d[i]) {
			dfs(i);
		}
	}
	for (i64 i = 1; i <= n; i++) {
		cout << vv[i].size() << " ";
		for (auto c : vv[i]) {
			cout << c << " ";
		}
		cout << endl;
	}
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}