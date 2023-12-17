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

char s[maxn];//树状数组 + 前缀和
void solve() {
	i64 n; cin >> (s + 1);
	n = strlen(s + 1);
	//n = (i64)st.size() - 1;
	//cout << st << endl;
	vector<i64>tr(n + 5, 0), c1(n + 5, 0), c2(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		c1[i] = c1[i - 1] + (s[i] == 'd');
		c2[i] = c2[i - 1] + (s[i] == 'u');
	}//前缀和
	auto lowbit = [&](i64 x)->i64{
		return x & -x;
	};
	auto add = [&](i64 id, i64 v) {
		for (; id <= n; id += lowbit(id)) {
			tr[id] += v;
		}
	};
	auto query = [&](i64 id)->i64{
		i64 ret = 0;
		for (; id > 0; id -= lowbit(id)) {
			ret += tr[id];
		}
		return ret;
	};
	for (i64 i = 1; i <= n; i++) {
		if (s[i] == 'd') {
			//if (c2[i - 1] and c2[n] - c2[i]) {
			add(1, c2[n] - c2[i]);
			add(i, c2[i] - c2[n]);
			add(i + 1, c2[i - 1]);
			add(n + 1, -c2[i - 1]);//这里用到了差分的思想
			//}
		}
	}
	i64 id = 0, vs = -inf;
	for (i64 i = 1; i <= n; i++) {
		if (s[i] == 'd') {

			i64 t = c2[i - 1] * (c2[n] - c2[i]);
			//cout << t << endl;
			if (t > vs) {
				id = i;
				vs = t;
			}
		} else if (s[i] == 'u') {
			i64 t = query(i);
			//cout << t << endl;
			if (t > vs) {
				id = i;
				vs = t;
			}
		}
	}
	s[id] = 'k';
	cout << (s + 1) << endl;
}
signed main() {
	solve();
}