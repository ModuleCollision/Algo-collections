/*二分经典问题,由于维护区间的信息具有单调性,故用双指针+二分维护*/
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

int stmax[maxn][30], stmin[maxn][30], lg[maxn];
int n, k, a[maxn];
void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> stmax[i][0];
		stmin[i][0] = stmax[i][0];
	}
	for (int i = 2; i <= 1e6; i++) {
		lg[i] = lg[i >> 1] + 1;
	}
	for (int len = 1; (1 << len) <= n; len++) {
		for (int i = 1; i + (1 << len) - 1 <= n; i++) {
			stmin[i][len] = min(stmin[i][len - 1], stmin[i + (1 << (len - 1))][len - 1]);
			stmax[i][len] = max(stmax[i][len - 1], stmax[i + (1 << (len - 1))][len - 1]);
		}//dp处理st表
	}
}
int query1(int l, int r) {
	int x = lg[r - l + 1];
	return max(stmax[l][x], stmax[r - (1 << x) + 1][x]);
}
int query2(int l, int r) {
	int x = lg[r - l + 1];
	return min(stmin[l][x], stmin[r - (1 << x) + 1][x]);
}
void solve() {
	init();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = i, r = n + 1; int ans1 = 0, ans2 = 0;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (query1(i, mid) - query2(i, mid) >= k) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}

		ans1 = r; l = i, r = n + 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (query1(i, mid) - query2(i, mid) > k) {
				r = mid;
			} else {
				l = mid + 1;
			}
		} ans2 = r;
		ans += max(0, ans2 - ans1); //这里的双指针需要二分来提高效率
	}
	cout << ans << endl;
}
signed main() {
	solve();
}


/*等价于如下写法: */
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
int stmax[maxn][30], stmin[maxn][30], lg[maxn];
int n, k, a[maxn];
void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> stmax[i][0];
		stmin[i][0] = stmax[i][0];
	}
	for (int i = 2; i <= 1e6; i++) {
		lg[i] = lg[i >> 1] + 1;
	}
	for (int len = 1; (1 << len) <= n; len++) {
		for (int i = 1; i + (1 << len) - 1 <= n; i++) {
			stmin[i][len] = min(stmin[i][len - 1], stmin[i + (1 << (len - 1))][len - 1]);
			stmax[i][len] = max(stmax[i][len - 1], stmax[i + (1 << (len - 1))][len - 1]);
		}//dp处理st表
	}
}
int query1(int l, int r) {
	int x = lg[r - l + 1];
	return max(stmax[l][x], stmax[r - (1 << x) + 1][x]);
}
int query2(int l, int r) {
	int x = lg[r - l + 1];
	return min(stmin[l][x], stmin[r - (1 << x) + 1][x]);
}
void solve() {
	init();
	int ans = 0;
	vector<int>w(n + 5, 0);
	iota(w.begin() + 1, w.begin() + n + 1, 1); int l = 0;
	auto cmp = [&](int x, int y) {
		return query1(l, x) - query2(l, x) < y;
	};
	auto cmp2 = [&](int x, int y) {
		return query1(l, x) - query2(l, x) <= y;
	};
	for (int i = 1; i <= n; i++) {
		l = i;
		int idx1 = lower_bound(w.begin() + l, w.begin() + 1 + n, k, cmp) - w.begin();
		int idx2 = lower_bound(w.begin() + l, w.begin() + 1 + n, k, cmp2) - w.begin();
		//cout << "#" << idx2 << " " << idx1 << endl;
		ans += max(0, idx2 - idx1); //这里的双指针需要二分来提高效率
	}
	cout << ans << endl;
}
signed main() {
	solve();
}