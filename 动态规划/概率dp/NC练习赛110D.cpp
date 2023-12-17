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


i64 dp[maxn], n, K;
char s[maxn];
void solve() {
	std::cin >> n >> K;
	auto inv = [&](i64 x) {
		i64 ret = 1, a = x, b = mod - 2;
		while (b) {
			if (b & 1) {
				ret = ret % mod * a % mod;
			}
			a = a * a % mod;
			b >>= 1;
		}
		return ret;
	};
	std::cin >> (s + 1);
	std::set<char>st;
	//st.insert('y'); st.insert('k'); st.insert('a'); st.insert('w'); st.insert('i');
	for (i64 i = 1; i <= n; i++) {
		if (s[i] == 'y' or s[i] == 'k' or s[i] == 'a' or s[i] == 'w' or s[i] == 'i') {
			dp[0] = (dp[0] % mod + 1) % mod;
		}
	}
	i64 d = inv(n % mod * 26 % mod);
	for (i64 i = 1; i <= K; i++) {
		i64 k = (dp[i - 1] % mod * 5 % mod + ((n - dp[i - 1]) % mod + mod) % mod * 21 % mod) % mod * d % mod;
		dp[i] = (dp[i] % mod + k % mod * dp[i - 1]) % mod;
		k = (dp[i - 1] % mod * 21 % mod) * d % mod;
		dp[i] = (dp[i] % mod + k % mod * ((dp[i - 1] - 1 + mod) % mod + mod) % mod) % mod;
		k = ((n - dp[i - 1]) % mod + mod) % mod * 5 % mod * d % mod;
		dp[i] = (dp[i] % mod + (dp[i - 1] % mod + 1) % mod * k % mod) % mod;
	}
	cout << (dp[K] % mod) << endl;
}
signed main() {
	solve();
}
