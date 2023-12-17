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
	i64 N; std::cin >> N;
	vector<i64>A(N + 5, 0);
	for (i64 i = 1; i <= N; i++)std::cin >> A[i];
	string s; std::cin >> s;
	s = " " + s;
	std::map<pair<char, i64>, vector<i64>>st;
	for (i64 i = 0; i < 3; i++) {
		st[ {'M', i}] = vector<i64>(N + 5, 0);
		st[ {'X', i}] = vector<i64>(N + 5, 0);
	}
	auto add = [&](char c, i64 f, i64 idx, i64 v) {
		for (; idx <= N; idx += (idx & -idx)) {
			st[ {c, f}][idx] += v;
		}
	};
	auto query = [&](char c, i64 f, i64 l, i64 r)->i64 {
		i64 v1 = 0, v2 = 0;
		l--;
		for (; r >= 1; r -= (r & -r)) {
			v1 += st[ {c, f}][r];
		}
		for (; l >= 1; l -= (l & -l)) {
			v2 += st[ {c, f}][l];
		}
		return v1 - v2;
	};
	for (i64 i = 1; i <= N; i++) {
		if (s[i] == 'M' or s[i] == 'X') {
			add(s[i], A[i], i, 1);
		}
	}
	auto cal = [&](set<i64>t)->i64 {
		vector<i64>tt;
		for (auto c : t)tt.push_back(c);
		for (i64 i = 0; i < tt.size(); i++) {
			if (tt[i] != i)return i;
		}
		return tt.size();
	};
	i64 ans = 0;
	for (i64 i = 1; i <= N; i++) {
		if (s[i] == 'E') {
			for (i64 j = 0; j < 3; j++) {
				for (i64 k = 0; k < 3; k++) {
					std::set<i64>f;
					f.insert(A[i]); f.insert(j); f.insert(k);
					auto h1 = query('M', j, 1, i - 1);
					auto h2 = query('X', k, i + 1, N);
					ans += (h1 * h2) * cal(f);
				}
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}