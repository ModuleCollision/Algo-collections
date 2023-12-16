/*二维差分模板*/
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
	i64 n; std::cin >> n;
	deque< i64>q;
	vector<pair< i64,  i64>>s(n + 5);
	vector< i64>w(n + 5);
	for ( i64 i = 1; i <= n; i++) {
		i64 v; std::cin >> v; //q.push_back(v);
		w[i] = v;
		s[i].second = v; s[i].first = i;
	}
	std::sort(s.begin() + 1, s.begin() + 1 + n, [&](pair< i64,  i64>x, pair< i64,  i64>y)->bool{
		return x.second < y.second;
	});
	//std::sort(q.begin(), q.end());
	std::sort(w.begin() + 1, w.begin() + 1 + n);
	i64 l = 1, r = n;
	for ( i64 i = 1; i <= n - 1; i++) {
		i64 d = w[r] - w[l];
		if (d == 0) {
			r--; continue;
		}
		//cout << "#" << d << s[l].first << " " << s[r].first << endl;
		if (d & 1) {
			d /= 2;
			i64 k = upper_bound(w.begin() + l, w.begin() + r + 1, w[l] + d) - w.begin() - l;
			i64 les = n - i + 1 - k;
			if (k >= les) {
				r--;
			} else {
				l++;;
			}
		} else {
			d /= 2;
			i64 k = upper_bound(w.begin(), w.begin() + r + 1, w[l] + d) - w.begin() - l;
			i64 les = n - i + 1 - k;
			if (k >= les) {
				r--; //q.pop_back();
			} else {
				l++; //q.pop_front();
			}
		}
	}
	cout << s[l].first << endl;
}
signed main() {
	solve();
}