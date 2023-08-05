#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
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
	__int128 ans = 0;
	if (n & 1) {
		__int128 k = 5;
		while (k <= n) {
			ans += (n / k + 1) / 2;
			k *= 5;
		}
	} else {
		__int128 k = 5;
		while (k <= 5) {
			ans += (n / k) / 2;
			k *= 5;
		}
	}
	for (__int128 j = 5; j <= n; j *= 5) {
		ans += j * (n / j) * (n / j - 1) / 2;
		ans += (n / j) * (n % j + 1);
	}
	write(ans / 2);
}
signed main() {
	solve();
}