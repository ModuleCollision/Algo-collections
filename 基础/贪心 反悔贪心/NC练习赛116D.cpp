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
	i64 n, m; std::cin >> n >> m;
	vector<i64>a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
	for (i64 i = 1; i <= n; i++) {
		cin >> a[i], a[i] += a[i - 1];
	}
	for (i64 i = 1; i <= n; i++)cin >> b[i];
	for (i64 i = 1; i <= n; i++)cin >> c[i];
	i64 mx = 0, mn = n;
	auto cal = [&](i64 i) {
		i64 l = i, r = n; i64 ret = i - 1;
		i64 v = b[i] * c[i];
		while (l <= r) {
			i64 mid = (l + r) >> 1;
			if (a[mid] - a[i - 1] <= v)l = mid + 1, ret = mid;
			else r = mid - 1;
		}
		return ret;
	};
	priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<>>q;
	for (i64 i = 1; i <= n; i++) {
		i64 pos = cal(i); i64 len = pos - i + 1;
		mx = max(mx, len); mn = min(mn, len);
		q.push({len, i});
	}
	/*贪心策略 ： */i64 ans = inf;
	while (m--) {
		auto p = q.top();
		q.pop(); c[p.second]++;
		i64 pos = cal(p.second);
		i64 len = pos - p.second + 1;
		mx = max(mx, len);
		p.first = len; q.push(p);
		mn = q.top().first;
		ans = min(ans, mx - mn);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}