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

struct edge {
	 i64 v;  i64 nx;
} e[maxn];
 i64 head[maxn]; i64 tot = 0;
void add_edge( i64 u, i64 v) {
	e[tot].v = v;
	e[tot].nx = head[u];
	head[u] = tot++;
}
struct cmp {
	bool operator()(pair< i64, i64>x, pair< i64, i64>y) {
		return x.first < y.first;
	}
};
void solve() {
	 i64 N, M, K; std::cin >> N >> M >> K;
	std::fill(head + 1, head + 1 + N, -1);
	vector<i64>dis(N + 5, -inf);
	for ( i64 i = 1; i <= M; i++) {
		 i64 u, v; std::cin >> u >> v;
		add_edge(u, v);
		add_edge(v, u);
	}
	vector<pair< i64, i64>>w(K + 5);
	for ( i64 i = 1; i <= K; i++) {
		std::cin >> w[i].first >> w[i].second;
	}
	std::set< i64>ans;
	priority_queue<pair< i64, i64>, vector<pair< i64, i64>>, cmp>q;
	for ( i64 i = 1; i <= K; i++) {
		std::cin >> w[i].first >> w[i].second;
		dis[w[i].first] = w[i].second;
		q.push({w[i].second, w[i].first});
	}
	while (q.size()) {
		auto [d, u] = q.top(); q.pop();
		if (d == 0)continue;
		for ( i64 i = head[u]; i != -1; i = e[i].nx) {
			 i64 v = e[i].v;
			if (dis[v] < dis[u] - 1) {
				dis[v] = dis[u] - 1;
				q.push({dis[v], v});
			}
		}
	}
	 i64 tot = 0;
	for ( i64 i = 1; i <= N; i++) {
		if (dis[i] != -inf)tot++;
	}
	cout << tot << endl;
	for ( i64 i = 1; i <= N; i++) {
		if (dis[i] != -inf)cout << i << " ";
	}
	cout << endl;
}
signed main() {
	solve();
}