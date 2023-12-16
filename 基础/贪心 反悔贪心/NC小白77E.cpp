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

struct cmp {
	bool operator()(const i64&a, const i64&b)const {
		return a < b;
	}
};
void solve() {
	i64 n, k; std::cin >> n >> k;
	i64 ps = 0;
	vector<i64>A(n + 1);
	for (i64 i = 1; i <= n; i++) {
		cin >> A[i]; if (A[i] >= 0)ps++;
	}
	priority_queue<i64, vector<i64>, cmp>q;
	i64 ww = 0, sw = 0; i64 ms = 0;
	for (i64 i = 1; i <= n; i++) {
		if (A[i] >= 0)ww += A[i];
		else {
			ms++;
			i64 cur = -A[i];/*贪心确保每一步操作都在提升负数*/
			/*首先确保有操作次数*/              /*两种情况, 还有多余的正数, 留一个剩余负数*/
			if (sw + cur <= k and (sw + cur <= ww or q.size() + 1 < ms)) {
				q.push(cur); sw += cur;
			} else {
				if (q.size() and q.top() > cur) {
					sw -= q.top(); q.pop(); q.push(cur); sw += cur;
				}
			}
		}
	}
	cout << q.size() + ps << endl;
}
signed main() {
	solve();
}