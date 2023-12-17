/*并查集+哈希表*/
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

struct dsu {
	vector<int>fa;
	void init(int n) {
		fa.reserve(n + 5);
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
	}
	int find(int x) {
		while (fa[x] != x) {
			x = fa[x] = fa[fa[x]];
		}
		return x;
	}
	void merge(int x, int y) {
		int x_ = find(x);
		int y_ = find(y);
		fa[x_] = y_;
		return;
	}
} dsu;
int cn[maxn];
bool vis[maxn]; int prime[maxn], cnt = 0;
void seieve() {
	for (int i = 2; i <= 1e6; i++) {
		if (!vis[i]) {
			prime[++cnt] = i;
		}
		for (int j = 1; j <= cnt and prime[j]*i <= 1e6; j++) {
			vis[prime[j]*i] = 1;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}
int n, w[maxn];
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}
int main() {
	seieve();
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	dsu.init(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; std::cin >> x >> y;
		if (vis[gcd(w[x],w[y])]) {
			dsu.merge(x, y);
		}
	}
	int ans = -0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		dsu.fa[i] = dsu.find(i);
		cn[dsu.fa[i]]++;
		ans = max(ans, cn[dsu.fa[i]]);
	}
	cout << ans << endl;
}


