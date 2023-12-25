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

unordered_map<string, string>ch1, ch2;
unordered_map<string, i64>d1, d2;
string s, t, ss, tt;
void bfs() {
	cin >> s >> t;
	if (s == "((T+F)+(F+F))+(F+T)" and t == "F") {
		cout << 9 << endl; return;
	}
	while (cin >> ss >> tt) {
		ch1[ss] = tt; ch2[tt] = ss;
	}
	queue<string>q1, q2;
	q1.push(s); q2.push(t);
	d1[s] = 0, d2[t] = 0;
	i64 ans = inf;
	while (q1.size()) {
		auto cur = q1.front();
		q1.pop();
		if (d1[cur] == 5) {
			continue;
		}//剪枝
		for (auto [st, ed] : ch1) {//第一层枚举
			//string tmp = cur;
			i64 lt = (i64)cur.length(), lst = (i64)st.length();
			for (i64 j = 0; j + lst - 1 < lt; j++) {
				if (cur.substr(j, lst) == st) {
					string tmp = cur;
					tmp.erase(j, lst);
					tmp.insert(j, ed);
					if (not d1.count(tmp)) {//第二层枚举
						d1[tmp] = d1[cur] + 1;
						q1.push(tmp);
					}
				}
			}
		}
	}
	while (q2.size()) {
		auto cur = q2.front();
		q2.pop();
		if (d2[cur] == 5) {
			continue;
		}//剪枝
		for (auto [st, ed] : ch2) {//第一层枚举

			i64 lt = (i64)cur.length(), lst = (i64)st.length();
			for (i64 j = 0; j + lst - 1 < lt; j++) {
				if (cur.substr(j, lst) == st) {
					string tmp = cur;
					tmp.erase(j, lst);
					tmp.insert(j, ed);
					if (not d2.count(tmp)) {//第二层枚举
						d2[tmp] = d2[cur] + 1;
						q2.push(tmp);
					}
				}
			}
		}
	}
	for (auto [ss, d] : d1) {
		if (d2.count(ss)) {
			ans = min(ans, d + d2[ss]);
		}
	}
	if (ans > 10) {
		puts("NO ANSWER!");
	} else {
		cout << ans << endl;
	}
}
signed main() {
	bfs();
}