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

char A[maxn];
void solve() {
	string s; cin >> s; i64 n = s.size();
	s = " " + s; i64 l = 1, r = n;
	for (i64 i = 1; i <= n; i += 2) {
		if (i == n)A[l] = s[i];
		else if (i == n - 1 or s[i] == s[i + 1]) {
			A[l++] = s[i + 1], A[r--] = s[i];
		} else if (s[i + 1] == s[n]) {
			swap(s[i], s[i + 2]); i -= 2;
		} else {
			A[r--] = s[i];
			for (i64 j = i + 1; j <= n; j++)A[l++] = s[j];
			i = n;
		}
	}
	for (i64 i = 1; i <= n; i++) {
		putchar(A[i]);
	}
	cout << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}