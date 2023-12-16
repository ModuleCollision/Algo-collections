/*300兆字节 1- 2 秒*/

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

void SG() {
	i64 n; std::cin >> n;
	vector<bool>vis(n + 5, 0);
	vector<i64>SG(n + 5, 0); i64 l, r; std::cin >> l >> r;
	function<void(i64)>dfs = [&](i64 x) {
		vis[x] = 1;
		if (not x) {
			SG[x] = 0; return;//无状态可转移是必输状态,SG值为0
		}
		std::set<i64>st;
		for (i64 i = max(0ll, x - r); i <= x - l; i++) {
			if (not vis[i]) {
				dfs(i);
			}
			st.insert(SG[i]);
		}
		//所有待转移的值取mex值,即为该状态的SG值
		for (i64 i = 0;; i++) {
			if (not st.count(i)) {
				SG[x] = i; return;
			}
		}//SG定理,直接求出其SG值
	};
	dfs(n);
	for (i64 i = 0; i <= n; i++) {
		cout << SG[i] << " ";
	}
	cout << endl;
}
void solve() {
	i64 l, r, n;
	std::cin >> n >> l >> r;
	auto SG = [&](i64 x) {
		return x % (l + r) / l;
	};
	vector<i64>A(n + 5, 0); i64 ans = 0;
	for (i64 i = 1; i <= n; i++) {
		cin >> A[i]; ans ^= SG(A[i]);
	}
	//SG定理,必输状态(先手输)的状态SG值为0,总状态的SG值所有子状态(每一位)SG值的异或和
	if (ans)puts("First");
	else puts("Second");
}
signed main() {
	solve();
}