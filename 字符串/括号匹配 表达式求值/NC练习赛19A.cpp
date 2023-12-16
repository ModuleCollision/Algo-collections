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
	i64 len; i64 dep; i64 ans;
};
char s[maxn];
void solve() {
	i64 ans = 0;
	std::cin >> (s + 1);
	i64 len = strlen(s + 1);
	vector<i64>tr[len + 5]; vector<i64>stk(len + 5, 0);
	i64 top = 0;
	for (i64 i = 1; i <= len; i++) {
		if (s[i] == '(') {
			tr[stk[top]].push_back(i);
			top++;
			stk[top] = i;
		} else if (s[i] == ')')top--;
	}
	function<sq(i64)>dfs = [&](i64 id)->sq{
		if (tr[id].size() == 0) {
			auto ret = (sq) {1, 1, 1};
			return ret;
		}
		i64 cnt = 0; i64 len = 0, dep = 0; i64 pre = 0;
		for (auto v : tr[id]) {
			auto k = dfs(v);
			cnt++;
			pre += k.ans;
			len += k.len;
			dep = max(dep, k.dep + 1);
		}
		i64 ans = (len + cnt + 1) * dep - pre;
		return (sq) {len + cnt + 1, dep, ans};
	};
	for (auto v : tr[0]) {
		auto k = dfs(v);
		ans += k.ans;
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}