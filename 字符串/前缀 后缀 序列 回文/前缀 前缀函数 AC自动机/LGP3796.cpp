/*AC自动机用于判定字符串中出现最多的文本串*/
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

i64 tot = 0, tr[maxn][26];
i64 fail[maxn], idx[maxn], val[maxn];
i64 cnt[maxn];
i64 n;
void solve() {
	memset(tr, 0, sizeof(tr));
	memset(fail, 0, sizeof(fail));
	memset(idx, 0, sizeof(idx));
	memset(val, 0, sizeof(val));
	memset(cnt, 0, sizeof(cnt));
	tot = 0;
	auto insert = [&](string s, i64 id) {
		i64 u = 0;
		for (i64 i = 0; i < s.size(); i++) {
			if (not tr[u][s[i] - 'a']) {
				tr[u][s[i] - 'a'] = ++tot;
			}
			u = tr[u][s[i] - 'a'];
		}
		idx[u] = id;
	};
	auto build = [&]() {
		queue<i64>q;
		for (i64 i = 0; i < 26; i++) {
			if (tr[0][i])q.push(tr[0][i]);
		}
		while (q.size()) {
			i64 u = q.front();
			q.pop();
			for (i64 i = 0; i < 26; i++) {
				if (tr[u][i]) {
					fail[tr[u][i]] = tr[fail[u]][i];
					q.push(tr[u][i]);
				} else {
					tr[u][i] = tr[fail[u]][i];
				}
			}
		}
	};
	auto query = [&](string t) {//代表
		i64 u = 0; i64 res = 0;
		for (i64 i = 0; i < t.size(); i++) {
			u = tr[u][t[i] - 'a'];
			for (i64 j = u; j; j = fail[j]) {
				val[j]++;
			}
		}
		for (int i = 0; i <= tot; i++) {
			if (idx[i]) {
				res = max(res, val[i]);
				cnt[idx[i]] = val[i];
			}
		}
		return res;
	};
	vector<string>s(n + 5);
	for (i64 i = 1; i <= n; i++) {
		std::cin >> s[i];
		insert(s[i], i);
	}
	build();
	string t; cin >> t;
	i64 x = query(t); cout << x << endl;
	for (i64 i = 1; i <= n; i++) {
		if (cnt[i] == x) {
			cout << s[i] << endl;
		}
	}
}
signed main() {
	while (cin >> n and n) {
		solve();
	}
}