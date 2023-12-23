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
constexpr f64 pi = acos(-1);

struct sq {
	f64 x, y; i64 c;
	f64 k;
};
void solve() {
	auto angle = [&](sq w) {
		return atan(w.y / w.x);
	};
	i64 n; std::cin >> n;
	vector<sq>a(n + 5);
	for (i64 i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].c;
	}

	auto eq = [&](f64 x, f64 y)->bool{
		return abs(x - y) < 1e-10;
	};
	i64 ans = 0;
	auto s = [&](i64 u) {//以一个点为极点将所有点按照极轴分为两部分
		vector<sq>b;
		vector cnt(5, vector<i64>(3, 0));//在某侧某颜色的点的个数
		auto cal = [&](i64 k, i64 x) {
			i64 ret = 1;
			for (i64 i = 0; i < 3; i++) {
				if (i != x)ret *= cnt[k][i];
			}
			return ret;
		};
		for (i64 i = 1; i <= n; i++) {
			if (i == u)continue;
			b.push_back(a[i]);
		}
		vector<i64>bl(n + 5, 0);//枚举每一次内切线时该点在线的哪一侧
		i64 m = b.size();
		for (i64 i = 0; i < m; i++) {
			b[i].x -= a[u].x; b[i].y -= a[u].y;
			b[i].k = angle(b[i]);
			if (b[i].k <= 0)b[i].k += pi;
		}
		std::sort(b.begin(), b.end(), [&](sq t1, sq t2)->bool{
			return t1.k < t2.k;
		});
		for (i64 i = 0; i <= 1; i++) {
			std::fill(cnt[i].begin(), cnt[i].end(), 0);
		}
		for (i64 i = 0; i < m; i++) {
			if (b[i].y < 0 or (eq(b[i].y, 0.0) and b[i].x > 0)) {
				bl[i] = 0;
			} else {
				bl[i] = 1;
			}
			cnt[bl[i]][b[i].c]++;
		}
		for (i64 i = 0; i < m; i++) {
			cnt[bl[i]][b[i].c]--;
			ans += cal(0, b[i].c) * cal(1, a[u].c);
			ans += cal(1, b[i].c) * cal(0, a[u].c);
			cnt[bl[i] ^= 1][b[i].c]++;
		}
	};
	for (i64 i = 1; i <= n; i++)s(i);
	cout << ans / 4 << endl;
}
signed main() {
	solve();
}