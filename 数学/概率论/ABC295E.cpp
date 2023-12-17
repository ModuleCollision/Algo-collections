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
	i64 w; i64 id;
} A[maxn];
void solve() {
	auto inv = [&](i64 x) {
		i64 b = mod - 2, a = x; i64 ret = 1;
		while (b) {
			if (b & 1) {
				ret = ret * a % mod;
			}
			a = a * a % mod;
			b >>= 1;
		}
		return ret;
	};
	i64 N, M, K; std::cin >> N >> M >> K;
	vector<i64>idx;
	for (i64 i = 1; i <= N; i++) {
		std::cin >> A[i].w;
		A[i].id = i;
		if (not A[i].w)idx.push_back(i);
	}
	std::map<i64, i64>tot;
	for (i64 i = 1; i <= M; i++) {
		for (auto c : idx) {
			A[c].w = i;
		}
		std::sort(A + 1, A + 1 + N, [&](sq x, sq y)->bool{
			return x.w < y.w;
		});
		tot[A[K].w]++;
		std::sort(A + 1, A + 1 + N, [&](sq x, sq y)->bool{
			return x.id < y.id;
		});
	}
	i64 ans = 0;
	for (auto s : tot) {
		i64 v = s.first, cnt = s.second;
		ans += v % mod * cnt % mod * inv(M) % mod;
	}
	cout << ans % mod << endl;
}
signed main() {
	solve();
}