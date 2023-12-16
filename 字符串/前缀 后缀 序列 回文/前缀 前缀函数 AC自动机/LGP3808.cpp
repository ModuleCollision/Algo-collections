/*AC自动机用于判定多少个下标不同的字符串出现于文本串中*/
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
i64 fail[maxn], e[maxn];
void solve() {
	i64 n; std::cin >> n;
	auto insert = [&](string s) {
		i64 u = 0;
		for (i64 i = 0; i < s.size(); i++) {
			if (not tr[u][s[i] - 'a']) {
				tr[u][s[i] - 'a'] = ++tot;
			}
			u = tr[u][s[i] - 'a'];
		}
		e[u]++;
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
			for (i64 j = u; j and e[j] != -1; j = fail[j]) {
				res += e[j]; e[j] = -1;//避免重复计算
			}
		}
		return res;
	};
	for (i64 i = 0; i < n; i++) {
		string s; std::cin >> s;
		insert(s);
	}
	build();
	string t; cin >> t;
	cout << query(t) << endl;
}
signed main() {
	solve();
}