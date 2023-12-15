/*300兆字节 1- 2 秒*/

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

//可根据题意模拟bfs
void solve() {
	int n, m; cin >> n >> m;
	vector<int>e[n + 5];
	vector<queue<int>>a(m + 5);
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int x; cin >> x;
			a[i].push(x);
			if (j == 0) {
				e[x].push_back(i);
			}
		}
	}
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (e[i].size() == 2) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : e[u]) {
			a[v].pop();
			if (not a[v].empty()) {
				e[a[v].front()].push_back(v);
				if (e[a[v].front()].size() == 2) {
					q.push(a[v].front());
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (a[i].size()) {
			puts("No");
			return;
		}
	}
	puts("Yes");
}
signed main() {
	solve();
}