#include<bits/stdc++.h>
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
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
void solve() {
	i64 n, k; cin >> n >> k;
	vector<pair<i64, i64>>a(n + 1);
	for (i64 i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin() + 1, a.begin() + 1 + n, [&](auto x, auto y)->bool{
		return x.second > y.second;
	});
	std::multiset<i64>st; i64 tot = 0;
	i64 ans = 0;
	for (i64 i = 1; i <= n; i++) {
		if (i <= k) {
			tot += a[i].first; st.insert(a[i].first);
			ans = max(ans, tot * a[i].second); continue;
		}
		if (a[i].first > (*st.begin())) {
			tot -= (*st.begin()); tot += a[i].first;
			st.insert(a[i].first);
			ans = max(ans, tot * a[i].second);
		}
	}
	cout << ans << "\n";
}
signed main() {
	solve();
}