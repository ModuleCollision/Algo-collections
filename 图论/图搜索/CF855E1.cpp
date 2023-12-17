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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	string t; cin >> t;
	if (n <= 7) {
		set<string> was;
		queue<string> q; q.push(s);
		was.insert(s);
		auto add = [&](string  s, int i, int j) {
			if (i >= 0 and i < j and j < n) {
				swap(s[i], s[j]);
				if (!was.count(s)) {
					was.insert(s);
					q.push(s);
				}
				swap(s[i], s[j]);
			}

		};

		while (!q.empty()) {
			s = q.front(); q.pop();
			for (int i = 0; i < n; ++i) {
				add(s, i, i + k);
				add(s, i, i + k + 1);
				add(s, i - k, i);
				add(s, i - k - 1, i);
			}
		}
		puts(was.count(t) ? "Yes" : "No");
		return;
	}
	map<char, int> cnt;
	for (char c : s) {
		cnt[c]++;
	}

	for (char c : t) {
		cnt[c]--;
	}
	bool f = true;
	for (auto [c, x] : cnt) {
		f &= (x == 0);
	}
	puts(f ? "Yes" : "No");
}

int main() {
	int T; std::cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}