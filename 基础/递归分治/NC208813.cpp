/*归并排序维护逆序数*/
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

int cnt[maxn];
int res = 0;
pair<int, int>a[maxn], b[maxn];
void qss(int l, int r) {
	if (l >= r) {
		return;
	}
	int mid = (l + r) >> 1;
	qss(l, mid);
	qss(mid + 1, r);
	int i = l, j = mid + 1, tp = l;
	while (i <= mid and j <= r) {
		if (a[i].second >= a[j].second) {
			b[tp++] = a[j++];

		} else {
			b[tp++] = a[i++];
			cnt[a[i - 1].first] += (j - mid - 1);
		}
	}
	for (int t = i; t <= mid; t++) {
		b[tp++] = a[t];
		cnt[a[t].first] += (j - mid - 1);
	}
	for (int t = j; t <= r; t++) {
		b[tp++] = a[t];
	}
	for (int t = l; t <= r; t++) {
		a[t] = b[t];
	}
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].second;
		a[i].first = i;
	}
	qss(1, n);
	for (int i = 1; i <= n; i++) {
		cout << cnt[i] << " ";
	}
}