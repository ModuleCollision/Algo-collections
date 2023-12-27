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
	i64 n; std::cin >> n; vector< i64>A(n + 5, 0);
	std::map< i64,  i64>cnt;
	for ( i64 i = 1; i <= n; i++) {
		std::cin >> A[i]; cnt[A[i]]++;
	}
	i64 q; std::cin >> q;
	if (n == 1) {
		while (q--) {
			i64 i, x; std::cin >> i >> x;
			cout << x << " ";
		}
		cout << endl; return;
	}
	std::multiset< i64>st;  i64 prev = -1;
	for (auto w = cnt.begin(); w != cnt.end(); w++) {
		if (prev != -1)
			st.insert((w->first) - prev);
		prev = w->first;
	}
	cnt[0]++;
	while (q--) {
		i64 i, x; std::cin >> i >> x;
		cnt[A[i]]--;
		if (cnt[A[i]] == 0) {
			auto s = cnt.upper_bound(A[i]);
			auto w = cnt.lower_bound(A[i]); w--;
			if (s != cnt.end())st.erase(st.find((s->first) - A[i]));
			if ((w->first) != 0)st.erase(st.find(A[i] - (w->first)));
			if (s != cnt.end() and (w->first != 0))st.insert((s->first) - (w->first));
			cnt.erase(A[i]);
		}
		A[i] = x; cnt[A[i]]++;
		if (cnt[A[i]] == 1) {
			auto s = cnt.upper_bound(A[i]);
			auto w = cnt.lower_bound(A[i]); w--;
			if (s != cnt.end())st.insert((s->first) - A[i]);
			if ((w->first) != 0)st.insert(A[i] - (w->first));
			if (s != cnt.end() and (w->first != 0))st.erase(st.find((s->first) - (w->first)));
		}
		i64 ans = (--cnt.end())->first;
		i64 p = *(--st.end());
		cout << ans + p << " ";
	}
	cout << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}