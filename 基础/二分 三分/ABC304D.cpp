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
	i64 W, H, N;
	std::cin >> W >> H >> N;
	vector<pair<i64, i64>>k(N + 5);
	for (i64 i = 1; i <= N; i++) {
		std::cin >> k[i].first >> k[i].second;
	}
	i64 x, y; std::cin >> x;
	vector<i64>A(x + 5);
	for (i64 i = 1; i <= x; i++) {
		std::cin >> A[i];
	}
	A[x + 1] = W;
	std::cin >> y;
	vector<i64>B(y + 5);
	for (i64 i = 1; i <= y; i++)std::cin >> B[i];
	B[y + 1] = H; std::map<pair<i64, i64>, i64>cnt;
	for (i64 i = 1; i <= N; i++) {
		i64 t1 = *lower_bound(A.begin() + 1, A.begin() + 2 + x, k[i].first);
		i64 t2 = *lower_bound(B.begin() + 1, B.begin() + 2 + y, k[i].second);
		cnt[ {t1, t2}]++;
	}
	i64 mx = -inf, mn = inf;
	for (auto [x, y] : cnt) {
		mx = max(mx, y);
		mn = min(mn, y);
	}
	if (cnt.size() < (x + 1) * (y + 1)) {
		cout << 0 << " " << mx << endl;
	} else {
		cout << mn << " " << mx << endl;
	}
}
signed main() {
	solve();
}