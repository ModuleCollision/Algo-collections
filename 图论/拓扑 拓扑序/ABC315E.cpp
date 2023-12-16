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

/*内向基环树*/
void solve() {
	i64 n; std::cin >> n;
	vector<vector<i64>>tr(n + 1), tr2(n + 1);
	vector<i64>d(n + 1, 0);
	for (i64 i = 1; i <= n; i++) {
		i64 p; std::cin >> p;
		for (i64 j = 1; j <= p; j++) {
			i64 v; std::cin >> v;
			tr[v].push_back(i);
			tr2[i].push_back(v);
			d[i]++;
		}
	}
	queue<i64>q; vector<bool>vis(n + 5);
	vector<i64>ans; q.push(1);
	for (i64 i = 1; i <= n; i++) {
		if (not d[i])q.push(i); vis[i] = 1;
	}
	vector<bool>f(n + 5, false);
	queue<i64>qe; qe.push(1); f[1] = 1;
	while (qe.size()) {
		auto cur = qe.front(); qe.pop();
		for (auto v : tr2[cur]) {
			if (f[v])continue;
			qe.push(v); f[v] = 1;
		}
	}
	while (q.size()) {
		auto cur = q.front(); q.pop();
		ans.push_back(cur);
		for (auto v : tr[cur]) {
			d[v]--;
			if (not d[v])q.push(v), vis[v] = 1;
		}
	}
	if (not vis[1])return;
	for (auto c : ans) {
		if (c != 1 and f[c])cout << c << " ";
	}
	cout << endl;
}
signed main() {
	solve();
}