/*并查集*/
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

int fa[maxn], d[maxn], n, k;
void init() {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
}
int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	int ff = find(fa[x]);
	d[x] += d[fa[x]];
	fa[x] = ff;
	return fa[x];
}
void solve() {
	std::cin >> n >> k;
	init();
	int s, x, y, ans = 0;
	for (int i = 1; i <= k; i++) {
		std::cin >> s >> x >> y;
		if (x > n or y > n) {
			ans++; continue;
		}
		if (s == 2 and x == y) {
			ans++; continue;
		}
		int tmp;
		if (s == 2) {
			tmp = 1;
		} else {
			tmp = 0;
		}
		int a = find(x), b = find(y);
		if (a == b) {
			if (((d[x] - d[y]) % 3 + 3) % 3 != tmp) {
				ans++;
			}
		} else {
			fa[a] = b;
			//依题意,d[x] + d[a] = d[y] + tmp
			d[a] = d[y] - d[x] + tmp;
		}
	}
	std::cout << ans << "\n";
}
int main() {
	solve();
}