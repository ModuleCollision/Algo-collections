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
	i64 N; std::cin >> N; vector<vector<i64>>tr(2 * N + 4);
	vector<i64>d(2 * N + 5); vector<bool>vis(2 * N + 5);
	std::map<string, i64>k;
	string a, b; i64 tot = 0;
	for (i64 i = 1; i <= N; i++) {
		std::cin >> a >> b;
		i64 u, v;
		if (not k.count(a))k[a] = ++tot;
		if (not k.count(b))k[b] = ++tot;
		u = k[a], v = k[b];
		tr[u].push_back(v); d[v]++;
	}
	i64 s = k.size(); queue<i64>q;
	for (i64 i = 1; i <= s; i++) {
		if (not d[i]) {
			q.push(i); vis[i] = 1;
		}
	}
	while (not q.empty()) {
		auto cur = q.front(); q.pop();
		for (auto v : tr[cur]) {
			d[v]--;
			if (not d[v]) {
				q.push(v), vis[v] = 1;
			}
		}
	} i64 cnt = 0;
	for (i64 i = 1; i <= s; i++) {
		if (vis[i])cnt++;
	}
	if (cnt == s) {
		puts("Yes");
	} else {
		puts("No");
	}
}
signed main() {
	solve();
}