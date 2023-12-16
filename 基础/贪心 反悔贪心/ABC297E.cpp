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

i64 N, K;
void solve() {
	std::cin >> N >> K;
	vector<i64>A(N + 5, 0);
	std::set<i64>st;
	for (i64 i = 1; i <= N; i++) {
		std::cin >> A[i];
	}
	std::sort(A.begin() + 1, A.begin() + 1 + N);
	st.insert(A[1]); i64 cur = A[1];
	while (--K) {
		i64 nxt = inf;
		for (i64 i = 1; i <= N; i++) {
			if (A[i] > cur) {
				nxt = min(nxt, A[i]); continue;
			}
			auto it = st.upper_bound(cur - A[i]);
			if (it == st.end())continue;
			else nxt = min(nxt, (*it) + A[i]);
		}
		st.insert(nxt);
		cur = nxt;
	}
	cout << cur << endl;
}
signed main() {
	solve();
}