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
	 i64 v;  i64 col;  i64 lr;  i64 idx;
};
struct cmp {
	bool operator()(const pair< i64,  i64>&x, const pair< i64,  i64>&y)const {
		return x.first < y.first;
	}
};
void solve() {
	 i64 n; std::cin >> n; vector< i64>a(n + 5), b(n + 5);
	priority_queue<pair< i64,  i64>, vector<pair< i64,  i64>>, cmp>q1, q2;
	for ( i64 i = 1; i <= n; i++)cin >> a[i];
	for ( i64 i = 1; i <= n; i++)cin >> b[i];
	 i64 ans = 0;
	vector<bool>exp(n + 5, false);
	vector< i64>col(n + 1); vector<sq>p;
	for ( i64 i = 1; i <= n; i++) {
		ans += abs(a[i] - b[i]);
		if (a[i] > b[i]) {
			col[i] = 1;
			p.push_back({b[i], col[i], 1, i});
			p.push_back({a[i], col[i], 2, i});
		} else {
			col[i] = 2;
			p.push_back({a[i], col[i], 1, i});
			p.push_back({b[i], col[i], 2, i});
		}
	}
	std::sort(p.begin(), p.end(), [&](sq x, sq y) {
		return x.v < y.v;
	});
	 i64 mx = 0;
	for (auto it : p) {
		if (it.col == 2 and it.lr == 1) {
			q1.push({b[it.idx], it.idx});
			while (q2.size() and exp[q2.top().second])q2.pop();
			if (q2.size()) {
				mx = max(mx, min(b[it.idx], q2.top().first) - a[it.idx]);
			}
		}
		else if (it.col == 2 and it.lr == 2) {
			exp[it.idx] = 1;
		}
		else if (it.col == 1) {
			if (it.lr == 1) {
				q2.push({a[it.idx], it.idx});
				while (q1.size() and exp[q1.top().second])q1.pop();
				if (q1.size()) {
					mx = max(mx, min(a[it.idx], q1.top().first) - b[it.idx]);
				}
			} else {
				exp[it.idx] = 1;
			}
		}
	}
	cout << ans - mx * 2 << endl;
}
signed main() {
	solve();
}
