/*内向基环树*/
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
	vector<i64>A(n + 5, 0); auto C = A;
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	vector<vector<i64>>tr(n + 1); vector<i64>d(n + 1);
	for (i64 i = 1; i <= n; i++)cin >> C[i];
	for (i64 i = 1; i <= n; i++) {
		tr[i].push_back(A[i]); d[A[i]]++;
	}
	std::queue<i64>q;
	vector<bool>vis(n + 5);
	for (i64 i = 1; i <= n; i++) {
		if (not d[i])q.push(i), vis[i] = 1;
	}
	std::vector<i64>ans;
	while (q.size()) {
		auto f = q.front(); q.pop(); ans.push_back(f);
		for (auto v : tr[f]) {
			d[v]--;
			if (not d[v])q.push(v), vis[v] = 1;
		}
	}

	for (i64 i = 1; i <= n; i++) {
		if (not vis[i]) {
			i64 cur = i;
			vector<i64>w; w.push_back(cur);
			i64 v = A[cur];
			while (v != cur) {
				w.push_back(v); v = A[v];
			}
			i64 xs = 1e10; i64 idx = -1;
			for (i64 j = 0; j < w.size(); j++) {
				vis[w[j]] = 1;
				if (C[w[j]] <= xs) {
					xs = C[w[j]]; idx = j;
				}
			}
			for (i64 j = idx + 1; j < w.size(); j++)ans.push_back(w[j]);
			for (i64 j = 0; j <= idx; j++)ans.push_back(w[j]);
		}
	}
	for (auto c : ans)cout << c << " ";
	cout << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}