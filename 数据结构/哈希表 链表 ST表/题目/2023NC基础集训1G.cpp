/*链表+set*/
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
	int nx; int pre;
} p[maxn];
set<int>st; int a[maxn];
void solve() {
	int n, m; i64 ans = 0;
	cin >> n >> m;
	vector<int>cnt(n + 5, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; ans += a[i];
		p[i].pre = i - 1;
		p[i].nx = i + 1;
		cnt[i] = 15;
		st.insert(i);
	}
	auto del = [&](int x) {
		p[p[x].nx].pre = p[x].pre;
		p[p[x].pre].nx = p[x].nx;
		st.erase(x);
	};
	auto f = [&](int x) {
		return round(10 * sqrt(x));
	};
	p[n].nx = 0;
	st.insert(maxn + 5);
	for (int i = 1; i <= m; i++) {
		int op; std::cin >> op;
		if (op == 1) {
			int l, r, k;
			std::cin >> l >> r >> k;
			int e = *st.lower_bound(l);
			for (int j = e; j and j <= r; j = p[j].nx) {
				if (cnt[j] <= 0)continue;
				int ned = min(k, cnt[j]);
				for (int kk = 1; kk <= ned; kk++) {
					cnt[j]--;
					ans -= a[j];
					a[j] = f(a[j]);
					ans += a[j];
				}
				if (cnt[j] <= 0)del(j);
			}
		} else {
			cout << ans << endl;
		}
	}
}
signed main() {
	solve();
}