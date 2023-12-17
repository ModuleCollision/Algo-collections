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
	i64 N, T, M; std::cin >> N >> T >> M;
	vector<set<i64>>k(T + 5);
	vector<set<i64>>tr(N + 5);
	for (i64 i = 1; i <= M; i++) {
		i64 A, B; std::cin >> A >> B;
		tr[A].insert(B); tr[B].insert(A);
	}
	i64 cur = 0; i64 ans = 0;
	function<void(i64)>dfs = [&](i64 idx) {
		if (idx >= N + 1) {
			if (cur == T)ans++;
			return;
		}
		for (i64 i = 1; i <= cur; i++) {
			bool f = 1;
			if (k[i].count(idx))continue;
			for (auto c : k[i]) {
				if (tr[c].count(idx)) {
					f = 0; break;
				}
			}
			if (not f)continue;
			k[i].insert(idx);
			dfs(idx + 1);
			k[i].erase(idx);
		}
		if (cur < T) {
			cur++;
			k[cur].insert(idx);
			dfs(idx + 1);
			k[cur].clear();
			cur--;
		}
	};
	dfs(1);
	cout << ans << endl;
}
signed main() {
	solve();
}