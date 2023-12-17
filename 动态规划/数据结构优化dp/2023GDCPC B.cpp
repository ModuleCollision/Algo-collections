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

//单调队列用于维护一定连续区间范围内的最值
void solve() {//优化方式, 单调队列优化dp
	i64 n, m; std::cin >> n;
	vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	n++;
	i64 l, r;
	std::cin >> m;
	vector<vector<i64>>p(n + 5), f(n + 5);
	for (i64 i = 1; i <= m; i++) {
		std::cin >> l >> r;
		p[l].push_back(r);
		f[r].push_back(l);
	}
	p[n].push_back(n); f[n].push_back(n);
	vector<i64>lim(n + 5, 0);
	for (i64 i = 1, j = 1, cur = 0; i <= n; i++) {
		for (auto x : f[i]) {
			if (x >= j) {
				cur++;
			}
		}
		while (cur > 0 and j <= i) {
			for (auto x : p[j]) {
				if (x <= i) {
					cur--;
				}
			}
			j++;
		}
		lim[i] = j;
	}
	vector<i64>q(n + 5, 0);
	i64 head = 1, tail = 0;
	vector<i64>dp(n + 5, 0);
	dp[0] = 0;//初始化为空队列
	for (i64 i = 1; i <= n; i++) {//从1开始维护
		i64 ls = lim[i - 1] - 1;
		while (head <= tail and dp[q[tail]] >= dp[i - 1]) {
			tail--;
		}
		q[++tail] = i - 1;//i = 1时, 前置序列最小值就是dp[0]
		while (q[head] < ls) {
			head++;
		}//维护dp前置序列中 下标为 lim[i - 1] - 1到i - 1范围的最小值
		dp[i] = dp[q[head]] + A[i];//查询前置dp序列的最小值,用单调队列实现

	}
	cout << dp[n] << endl;
}
signed main() {
	ios::sync_with_stdio(false); cin.tie(nui64ptr);
	cout.tie(nui64ptr);
	i64 T; cin >> T;
	while (T--) {
		solve();
	}
}
