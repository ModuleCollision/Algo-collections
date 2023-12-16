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
	i64 n, q; std::cin >> n >> q;
	vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	vector<i64>pre(n + 5, 0);
	i64 cur = 0; std::set<i64>st;
	vector<i64>cnt(n + 5); vector<i64>idx(n + 5, 0);
	i64 tot = 0;
	for (i64 i = 1; i <= n; i++) {
		if (A[i] & 1)pre[i] = i, cur = i, st.insert(i), idx[i] = ++tot;
		else pre[i] = cur;
		cnt[i] += cnt[i - 1];
		cnt[i] += (A[i] & 1);
	}
	st.insert(0);
	cur = n + 1; vector<i64>suf(n + 5, 0);
	for (i64 i = n; i >= 1; i--) {
		if (A[i] & 1)suf[i] = i, cur = i;
		else suf[i] = cur;
	}
	st.insert(n + 1);
	bool curr = 0;
	vector ct(n + 5, array<i64, 2> {0, 0});
	for (i64 i = 1; i <= n; i++) {
		ct[i][0] += ct[i - 1][0];
		ct[i][1] += ct[i - 1][1];
		if (A[i] & 1)curr ^= 1;
		else {

			ct[i][curr] += 1;
		}
	}
	while (q--) {
		i64 l, r, k; std::cin >> l >> r >> k;
		i64 f = cnt[r] - cnt[l - 1];
		if (r - l + 1 < k) {
			puts("NO"); continue;
		}
		if (not f) {
			puts("YES"); continue;
		}
		if (f & 1) {
			puts("NO"); continue;
		}
		f /= 2;
		auto p1 = st.lower_bound(l);
		i64 ws = idx[*p1]; i64 pre = 0;
		if (ws & 1) {
			pre = ct[r][0] - ct[l - 1][0];
		} else pre = ct[r][1] - ct[l - 1][1];
		i64 high = pre + f;
		if (k > high)puts("NO");
		else puts("YES");
	}
}
signed main() {
	i64 T; std::cin >> T;
	while (T --)
		solve();
}

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
	i64 n, q; std::cin >> n >> q;
	vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	vector<i64>pre1(n + 5, 0), pre2(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		A[i] += A[i - 1];
		pre1[i] += pre1[i - 1];
		pre2[i] += pre2[i - 1];
		if (A[i] & 1)pre2[i]++;
		else pre1[i]++;

	}
	while (q--) {
		i64 l, r, k; std::cin >> l >> r >> k;
		i64 f = cnt[r] - cnt[l - 1];
		if (A[l - 1] & 1) {
			if (pre2[r] - pre2[l - 1] >= k and (A[r] - A[l - 1]) % 2 == 0) {
				puts("YES");
			} else puts("NO");
		} else {
			if (pre1[r] - pre1[l - 1] >= k and (A[r] - A[l - 1]) % 2 == 0) {
				puts("YES");
			} else puts("NO");
		}
	}
}
signed main() {
	i64 T; std::cin >> T;
	while (T --)
		solve();
}