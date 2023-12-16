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
	i64 N, M; std::cin >> N >> M;
	vector<i64>s[N + 5], f[M + 5];
	vector<bool>vis(N + 5, 0);
	for (i64 i = 1; i <= N; i++) {
		i64 k; std::cin >> k;
		for (i64 j = 1; j <= k; j++) {
			i64 v; std::cin >> v;
			s[i].push_back(v);
			f[v].push_back(i);
		}
	}
	vector<i64>dis(M + 5, -1);
	vector<bool>vs(M + 5, 0);
	queue<i64>q; q.push(1); dis[1] = 0; vs[1] = 1;
	while (q.size()) {
		auto x = q.front(); q.pop();
		for (auto i : f[x]) {
			if (not vis[i]) { //还没有被合并过
				vis[i] = true;
				for (auto v : s[i]) {
					if (vs[v]) continue;
					vs[v] = 1;
					dis[v] = dis[x] + 1; q.push(v);
				}
			}
		}
	}
	i64 ans = dis[M]; if (ans != -1)ans--;
	cout << ans << endl;
}
signed main() {
	solve();
}