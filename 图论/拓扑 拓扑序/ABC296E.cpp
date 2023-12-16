/*内向基环树*/
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

vector<i64>tr[maxn]; i64 N;
void solve() {
	std::cin >> N; i64 A;
	vector<i64>d(N + 5, 0);
	for (i64 i = 1; i <= N; i++) {
		std::cin >> A; tr[i].push_back(A);
		d[A]++;
	}
	queue<i64>q; vector<bool>vis(N + 5);
	for (i64 i = 1; i <= N; i++) {
		if (not d[i]) {
			q.push(i); vis[i] = 1;
		}
	}
	while (not q.empty()) {
		auto cur = q.front(); q.pop();
		for (auto v : tr[cur]) {
			d[v]--;
			if (not d[v]) {
				q.push(v); vis[v] = 1;
			}
		}
	}
	i64 ans = 0;
	for (i64 i = 1; i <= N; i++) {
		if (not vis[i]) {
			i64 t = i; ans++;
			vis[t] = 1;
			while (1) {
				bool f = 1;
				for (auto v : tr[t]) {
					if (not vis[v]) {
						f = 0; t = v; vis[t] = 1; ans++; break;
					}
				}
				if (f)break;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}