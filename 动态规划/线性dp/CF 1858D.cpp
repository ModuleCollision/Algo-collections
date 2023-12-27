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
	i64 n, k; std::cin >> n >> k; string s; cin >> s; s = " " + s;
	vector pre(n + 5, vector<i64>(n + 5, 0)); vector suf(n + 5, vector<i64>(n + 5, 0));
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 0; j <= n; j++) {
			if (s[i] == '0')
				pre[i][j] = max(pre[i][j], pre[i - 1][j] + 1);
			else if (j >= 1)pre[i][j] = max(pre[i][j], pre[i - 1][j - 1] + 1);
		}
	}
	for (i64 i = n; i >= 1; i--) {
		for (i64 j = 0; j <= n; j++) {
			if (s[i] == '0')suf[i][j] = max(suf[i][j], suf[i + 1][j] + 1);
			else if (j >= 1)suf[i][j] = max(suf[i][j], suf[i + 1][j - 1] + 1);
		}
	}
	vector<i64>w(n + 5), t(n + 5);
	for (i64 i = 1; i <= n; i++) {
		if (s[i] == '0')continue;
		i64 l = i; w[i] = l - 1;
		while (i + 1 <= n and s[i + 1] == '1') {
			i++; w[i] = l - 1;
		}
	}
	for (i64 i = n; i >= 1; i--) {
		if (s[i] == '0')continue;
		i64 l = i; t[i] = l + 1;
		while (i - 1 >= 1 and s[i - 1] == '1') {
			i--; t[i] = l + 1;
		}
	}
	vector<i64>p(n + 5), q(n + 5);
	for (i64 i = 1; i <= n; i++) {
		p[i] = max(p[i], p[i - 1]);
		if (s[i] == '1')p[i] = max(p[i], i - w[i]);
	}
	for (i64 i = n; i >= 1; i--) {
		q[i] = max(q[i], q[i + 1]);
		if (s[i] == '1')q[i] = max(q[i], t[i] - i);
	}
	i64 ans = 0; i64 len1 = 0, len2 = 0;
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 0; j <= k; j++) {
			i64 v1 = pre[i][j] + suf[i + 1][k - j];
			i64 v2 = max(p[i - pre[i][j]], q[i + suf[i][k - j]]);
			if (v1 > len1) {
				len1 = v1, len2 = v2;
			} else if (v1 == len1) {
				if (v2 > len2)len2 = v2;
			} else continue;
		}
	}
	for (i64 i = 1; i <= n; i++) {
		cout << len1*i + len2 << " ";
	}
	cout << endl;
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}