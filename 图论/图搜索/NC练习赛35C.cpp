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

 i64 A, B; std::map< i64,  i64>dis;
void solve() {
	std::cin >> A >> B;
	dis.clear();
	queue< i64>q;
	dis[A] = 0;
	auto f = [&]( i64 x) {
		return (x % mod * x % mod * x % mod + x % mod * x) % mod;
	};
	auto g = [&]( i64 x) {
		return (((x % mod * x % mod * x) % mod - (x * x) % mod) % mod + mod) % mod;
	};
	q.push(A);
	while (not q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur == B) {
			cout << dis[cur] << endl;
			return;
		}
		 i64 nxt = f(cur);
		if (dis.count(nxt))continue;
		dis[nxt] = dis[cur] + 1;
		q.push(nxt);
		nxt = g(cur);
		if (dis.count(nxt))continue;
		dis[nxt] = dis[cur] + 1;
		q.push(nxt);
	}
}
signed main() {
	 i64 T; std::cin >> T;
	while (T--)
		solve();
}