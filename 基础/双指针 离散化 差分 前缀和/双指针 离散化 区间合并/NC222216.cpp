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

int dp1[maxn], dp2[maxn];
int cnt[30];
int n, m; char s[maxn];
void solve() {
	cin >> n >> m;
	scanf("%s", s + 1);
	for (int l = 1, r = 1; r <= n; r++) {
		cnt[s[r] - 'a']++;
		if (cnt[s[r] - 'a'] > m) {
			while (cnt[s[r] - 'a'] > m) {
				cnt[s[l] - 'a']--;
				l++;
			}
		}
		dp1[r] = max(dp1[r - 1], r - l + 1);
	}
	memset(cnt, 0, sizeof(cnt));
	for (int l = n, r = n; l >= 1; l--) {
		cnt[s[l] - 'a']++;
		while (cnt[s[l] - 'a'] > m) {
			cnt[s[r] - 'a']--;
			r--;
		}
		dp2[l] = max(dp2[l + 1], r - l + 1);
	}
	int ans = 0;
	memset(cnt, 0, sizeof(cnt));
	for (int r = 1, l = 1; r <= n; r++) {
		cnt[s[r] - 'a']++;
		while (cnt[s[r] - 'a'] > m) {
			cnt[s[l] - 'a']--;
			l++;
		}
		ans = max(ans, dp1[l - 1] + dp2[r + 1] + r - l + 1);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}