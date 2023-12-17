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

vector<i64>tr[maxn];
void solve() {
	i64 N, M, K;
	std::cin >> N >> M;
	i64 u, v;
	for (i64 i = 1; i <= M; i++) {
		std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	std::cin >> K;
	vector<i64>p(K + 5, 0), d(K + 5, 0);
	for (i64 i = 1; i <= K; i++) {
		std::cin >> p[i] >> d[i];
	}
	vector<i64>c(N + 5, 1);
	for (i64 i = 1; i <= K; i++) {
		queue<i64>q; vector<i64>dis(N + 5, -1);
		q.push(p[i]);
		dis[p[i]] = 0;
		while (q.size()) {
			auto cur = q.front(); q.pop();
			if (dis[cur] < d[i]) {
				c[cur] = 0;
			}
			for (auto v : tr[cur]) {
				if (dis[v] != -1)continue;
				dis[v] = dis[cur] + 1;
				q.push(v);
			}
		}
	}
	queue<i64>q; vector<i64>dis(N + 5, -1);
	for (i64 i = 1; i <= N; i++) {
		if (c[i]) {
			q.push(i); dis[i] = 0;
		}
	}
	while (q.size()) {
		auto cur = q.front(); q.pop();
		for (auto v : tr[cur]) {
			if (dis[v] != -1)continue;
			dis[v] = dis[cur] + 1;
			q.push(v);
		}
	}
	for (i64 i = 1; i <= K; i++) {
		if (dis[p[i]] != d[i]) {
			puts("No"); return;
		}
	}
	puts("Yes");
	for (i64 i = 1; i <= N; i++) {
		cout << c[i];
	}
	cout << endl;
}
signed main() {
	solve();
}