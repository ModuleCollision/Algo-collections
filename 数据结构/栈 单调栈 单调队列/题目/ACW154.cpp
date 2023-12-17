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
	i64 n, k; std::cin >> n >> k;
	vector<i64>q(n + 5, 0);
	i64 h = 1, t = 0;//初始化为空序列
	vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];

	for (i64 i = 1; i < k; i++) {
		while (h <= t and A[q[t]] >= A[i])t--;
		q[++t] = i;
	}
	for (i64 i = k; i <= n; i++) {
		while (h <= t and A[q[t]] >= A[i])t--;
		q[++t] = i;//动态维护 i - k + 1 到 k的最小值
		while (q[h] <= i - k)h++;
		cout << A[q[h]] << " ";
	}
	cout << endl;
	h = t = 0;
	for (i64 i = 1; i < k; i++) {
		while (h <= t and A[q[t]] <= A[i])t--;
		q[++t] = i;
	}
	for (i64 i = k; i <= n; i++) {
		while (h <= t and A[q[t]] <= A[i])t--;//动态维护一定范围内的最大值
		q[++t] = i;
		while (q[h] <= i - k)h++;
		cout << A[q[h]] << " ";
	}
	cout << endl;
}
signed main() {
	solve();
}