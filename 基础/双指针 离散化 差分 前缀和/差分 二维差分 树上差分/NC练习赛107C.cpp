/*Ai64 glory, ai64 honor, victory is upon us!*/
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

i64 tr[maxn], n, q, w, x, a[maxn], p;
//map<i64, i64>st;
void solve() {
	cin >> n >> q >> w; w += 2;
	for (i64 i = 1; i <= n; i++) {
		cin >> a[i]; a[i]++;
		//st[i] = a[i];
	}
	//std::sort(a + 1, a + 1 + n);
	auto lowbit = [&](i64 x)->i64{
		return x & -x;
	};
	auto add = [&](i64 id, i64 v) {
		for (; id <= w; id += lowbit(id)) {
			tr[id] += v;
		}
	};
	auto query = [&](i64 id)->i64{
		i64 ret = 0;
		for (; id >= 1; id -= lowbit(id)) {
			ret += tr[id];
		}
		return ret;
	};
	i64 ans = 0;
	for (i64 i = 1; i <= n; i++) {
		i64 s = w - a[i];
		add(a[i], 1);
		ans += query(s);
	}
	while (q--) {
		std::cin >> p >> x; x++;
		i64 cur = a[p]; a[p] = x;
		//st[p] = x;
		ans -= query(w - cur);
		add(cur, -1);
		add(x, 1);
		ans += query(w - x);
		cout << ans << endl;
	}
	/*本质是一个差分*/
}
signed main() {
	solve();
}