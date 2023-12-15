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
	i64 ans = inf;
	function<i64(i64, i64, i64&, i64&)>exgcd = [&] (i64 a, i64 b, i64 & x, i64 & y) {
		if (b == 0) {
			x = 1; y = 0;
			return a;
		}
		i64 d = exgcd(b, a % b, x, y);
		i64 temp = x; x = y;
		y = temp - a / b * y;
		return d;
	};
	i64 n, m, x; std::cin >> n >> m >> x;
	vector<i64>A(m + 5, 0);
	for (i64 i = 1; i <= m; i++)cin >> A[i];
	//swap(A[1], A[m]);
	vector<i64>pre(m + 1);
	for (i64 i = 1; i <= m; i++) {
		pre[i] = pre[i - 1] + A[i];
	}
	i64 tot = pre[m];
	i64 w, s;
	i64 d = exgcd(tot, n, w, s);
	//cout << d << " " << w << " " << s << endl;
	for (i64 i = 0; i <= m - 1; i++) {
		i64 cur = -(x + pre[i]);
		if (cur % d) {
			continue;
		}
		i64 nn = n; nn /= d;
		i64 xo = (w * cur / d % nn + nn) % nn;
		i64 yo = (cur - xo * tot) / n;
		//cout << xo << " " << yo << endl;
		ans = min(ans, xo * m + i);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}