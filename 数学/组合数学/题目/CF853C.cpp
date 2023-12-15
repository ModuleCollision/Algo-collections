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

char s[maxn];
void solve() {
	i64 n, m; std::cin >> n >> m;
	vector<i64>p(m + 5, 0), v(m + 5, 0);
	vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	for (i64 i = 1; i <= m; i++)cin >> p[i] >> v[i];
	vector<i64>cnt(n + m + 5, 0), pos(n + m + 5, 0);//维护某数在数列中的总出现次数
	//维护某个位的上一次修改
	i64 ans = 0;
	for (i64 i = 1; i <= m; i++) {
		if (A[p[i]] != v[i]) {
			cnt[A[p[i]]] += i - pos[p[i]];
			pos[p[i]] = i;
		}//每次修改后统计该位修改前对该数出现总次数的贡献
		A[p[i]] = v[i];
	}
	for (i64 i = 1; i <= n; i++) {
		cnt[A[i]] += m - pos[i] + 1;
	}
	for (i64 i = 1; i <= n + m; i++) {
		ans += cnt[i] * (m + 1 - cnt[i]);//考虑两数不同的贡献
		ans += cnt[i] * (cnt[i] - 1) / 2;//组合数
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}