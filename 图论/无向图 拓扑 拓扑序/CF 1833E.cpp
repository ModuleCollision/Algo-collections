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
	vector<i64>A(n + 1);
	vector<i64>d(n + 5, 0), vis(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		i64 x; std::cin >> x; A[i] = x;
		d[x]++;
	}//每个点的出度都为1
	i64 ans1 = 0, ans2 = 0; i64 idx = 0;
	auto topsort = [&](i64 u) {
		i64 cur = u, sz = 1;
		vis[cur] = idx; bool f1 = 0, f2 = 0;
		bool f = 0;
		while (1) {
			cur = A[cur];
			if (cur == u)f = 1;
			if (vis[cur]) {
				if (vis[cur] == idx)f1 = 1;
				else f2 = 1;
				break;
			}
			vis[cur] = idx;
			sz++;
		}
		if (f and sz > 2)++ans2;//如果整个连通块是一个环
		else if (f1)++ans1;
	};
	//如果整个连通块是一个环,那么不能和其他联通块合并
	for (i64 i = 1; i <= n; i++) {
		if (not d[i] and not vis[i]) {//入度为零
			idx++;
			topsort(i);
		}
	}
	for (i64 i = 1; i <= n; i++) {
		if (not vis[i]) {
			idx++;
			topsort(i);
		}
	}
	cout << ans2 + (ans1 ? 1 : 0) << " " << ans2 + ans1 << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}
/*实现2*/
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
	vector<i64>A(n + 1);
	vector<i64>d(n + 5, 0), vis(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		i64 x; std::cin >> x; A[i] = x;
		d[x]++;
	}//每个点的出度都为1
	i64 ans1 = 0, ans2 = 0; i64 idx = 0;
	bool f1 = 0, f = 0;
	function<i64(i64, i64)>dfs = [&](i64 u, i64 p) {
		if (vis[u]) {
			if (u == p) {
				f = 1;
			}
			if (vis[u] == idx) {
				f1 = 1;
			} return 1i64;
		}
		vis[u] = idx;
		i64 w = dfs(A[u], p) + 1; return w;
	};
	//如果整个连通块是一个环,那么不能和其他联通块合并
	for (i64 i = 1; i <= n; i++) {
		if (not d[i]) {//入度为零
			idx++; f1 = 0, f = 0;
			vis[i] = idx;
			i64 sz = dfs(A[i], i);
			if (f and sz > 2)++ans2;
			else if (f1)++ans1;
		}
	}
	for (i64 i = 1; i <= n; i++) {
		if (not vis[i]) {
			idx++; f1 = 0, f = 0;
			vis[i] = idx;
			i64 sz = dfs(A[i], i);
			if (f and sz > 2)++ans2;
			else if (f1)++ans1;
		}
	}
	cout << ans2 + (ans1 ? 1 : 0) << " " << ans2 + ans1 << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}