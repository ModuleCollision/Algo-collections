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
	i64 ps = 0;
	string s; std::cin >> s;
	s = " " + s;
	vector<i64>pre(n + 5, 0);
	vector<i64>pre2(n + 5, 0);
	vector<i64>f(n + 5); i64 cnt = 0;
	i64 ws = 1;
	std::set<i64>st; st.insert(0);
	for (i64 i = 1; i <= n; i++) {
		pre[i] += pre[i - 1];
		pre2[i] += pre2[i - 1];
		if (s[i] == 'A') {
			f[i] = ++cnt;
			ws = -ws;
			st.insert(i);
			pre[i]++;
		} else if (s[i] == 'B') {
			pre2[i] = pre2[i - 1] + (ws * 1);
		}
	}
	//cout << pre2[n] - pre2[0] << endl;
    string x; 
	while (q--) {
		i64 l, r; std::cin >> l >> r;
		std::cin >> x;
		i64 ms = (1 << (x.size()));
		l = ((ps ^ l) % n) + 1;
		r = ((ps ^ r) % n) + 1;
		if (l > r)swap(l, r);
		i64 cur = 0;
		for (i64 i = x.size() - 1; i >= 0; i--) {
			if (x[i] == '1')
				cur = (cur % ms + (1 << (x.size() - 1 - i))) % ms;
		}
		i64 v = pre2[r] - pre2[l - 1];
		auto pp = st.lower_bound(l);
		i64 pos = f[*pp];
		if (pos % 2 == 0) {
			v = ((0 - v) % ms + ms) % ms;
		}
		string res = "";
		cur = (cur % ms + v) % ms;
		if ((pre[r] - pre[l - 1]) & 1) {
			i64 ans = ((((1 << x.size()) - 1) - cur) % ms + ms) % ms;
			for (i64 i = 0; ans >> i; i++) {
				res += (char)('0' + ((ans >> i) & 1));
			}
			ps = ans;
		} else {
			i64 ans = (cur) % ms;
			for (i64 i = 0; i < x.size(); i++) {
				res += (char)('0' + ((ans >> i) & 1));
			}
			ps = ans;
		}
		reverse(res.begin(), res.end());
		cout << res << endl;
	}
}
signed main() {
	solve();
}