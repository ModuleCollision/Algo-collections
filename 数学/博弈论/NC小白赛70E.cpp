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
	vector<bool>vis(maxn, 0);
	vector<i64>SG(maxn, 0);
	function<void(i64)>dfs = [&](i64 x) {
		vis[x] = 1;
		if (x == 1 or x == 2) {
			SG[x] = 0; return;//遇到末状态则为必输状态,SG值为0
			//SG值为正则必胜,为零则必输
		}
		set<i64>st;
		if (x & 1) {
			for (i64 i = 1; i <= x / 2; i++) {
				if (not vis[i])dfs(i);
				st.insert(SG[i]);
			}
		} else {
			for (i64 i = 1; i < x / 2; i++) {
				if (not vis[i])dfs(i);
				st.insert(SG[i]);
			}
		}
		for (i64 i = 0;; i++) {
			if (not st.count(i)) {
				SG[x] = i; return;
			}
		}
	};
	dfs(maxn);
	for (i64 i = 1; i <= 100; i++) {
		cout << i << ":" << (SG[i] == ((i64)log2(i + 1)) - 1) << endl;
	}
}
void solve() {
	//kk();//根据SG函数打个表发现规律
	i64 n, m; cin >> n >> m;
	i64 ans = 0;
	n = (i64)(log2(n + 1) - 1);
	m = (i64)(log2(m + 1) - 1);
	ans = ans ^ n ^ m;//求每一个位(每一个子问题)的SG函数,看亦或和
	//异或和为正则先手必胜,异或和为0则先手必输
	if (ans) {
		puts("Alice");
	} else {
		puts("Bob");
	}
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}