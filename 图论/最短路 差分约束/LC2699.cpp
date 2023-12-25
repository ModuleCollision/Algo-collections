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

struct sq {
	int u; i64 dis;
	bool operator<(const sq&b)const {
		return dis > b.dis;
	}
};
class Solution {
public:
	vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
		vector<vector<pair<int, int>>>G(n + 5);
		auto cons = [&](i64 idx, int target) {
			for (int i = 0; i < n; i++)G[i].clear();
			for (auto e : edges) {
				int u = e[0], v = e[1], w = e[2];
				if (w != -1) {
					G[u].push_back({v, w});
					G[v].push_back({u, w});
				} else {
					if (idx >= target - 1) {
						G[u].push_back({v, target});
						G[v].push_back({u, target});
						idx -= (target - 1);
					} else {
						G[u].push_back({v, 1 + idx});
						G[v].push_back({u, 1 + idx});
						idx = 0;
					}
				}
			}
		};

		auto dij = [&](int s, int t) {
			vector<i64>dis(n + 5, inf);
			vector<bool>vis(n + 5, false);
			dis[s] = 0; priority_queue<sq>q;
			q.push({s, 0});
			while (q.size()) {
				auto [u, w] = q.top(); q.pop();
				vis[u] = 1;
				for (auto [v, d] : G[u]) {
					if (dis[u] + d < dis[v]) {
						dis[v] = dis[u] + d;
						if (not vis[v]) {
							q.push({v, dis[v]});
						}
					}
				}
			}
			return dis[t];
		};
		i64 k = 0;
		for (auto e : edges) {
			if (e[2] == -1)k++;
		}
		cons(0ll, target);
		if (dij(source, destination) > target) {
			return {};
		}
		cons((i64)k * (target - 1), target);
		if (dij(source, destination) < target) {
			return {};
		}
		i64 l = 0, r = (i64)k * (target - 1), ans = 0;
		while (l <= r) {
			i64 mid = (l + r) >> 1;
			cons(mid, target);
			if (dij(source, destination) >= target) {
				ans = mid; r = mid - 1;
			} else {
				r = mid + 1;
			}
		}
		for (auto e : edges) {
			if (e[2] == -1) {
				if (ans >= target - 1) {
					e[2] = target;
					ans -= target - 1;
				} else {
					e[2] = 1 + ans;
					ans = 0;
				}
			}
		}
		return edges;
	}
};