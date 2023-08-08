#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
__int128 t[30];
void solve() {
	auto read = [&]()->__int128{
		__int128 x = 0, f = 1;
		char ch = getchar();
		while (not isdigit(ch)) {
			if (ch == '-')f = -1;
			ch = getchar();
		}
		while (isdigit(ch))x = x * 10 + ch - '0', ch = getchar();
		return x * f;
	};
	function<void(__int128)> write = [&](__int128 x) {
		if (x < 0)putchar('-'), x = -x;
		if (x > 9)write(x / 10);
		putchar(x % 10 + '0');
	};
	__int128 n = read();
	t[1] = 5;
	for (int i = 2; i <= 26; i++) {
		t[i] = t[i - 1] * 5;
	}
	__int128 ans = 0;
	auto ws = [&](__int128 k)->__int128{
		if (n < k)return 0;
		return (n - k) / 2 + 1;
	};
	for (int i = 1; i <= 26; i++) {
		__int128 cur = t[i], curr = cur * 2;
		if (n >= cur) {
			__int128 r = (n - cur) / 2 + 1;
			__int128 c = (n - cur) / curr + 1;
			__int128 l = r - (c - 1) * cur;
			ans += (l + r) * c / 2;
		}
		if (n >= curr) {
			__int128 r = (n - curr) / 2 + 1;
			__int128 c = (n - curr) / curr + 1;
			__int128 l = r - (c - 1) * cur;
			ans += (l + r) * c / 2;
		}
	}
	write(ans);
}
signed main() {
	solve();
}