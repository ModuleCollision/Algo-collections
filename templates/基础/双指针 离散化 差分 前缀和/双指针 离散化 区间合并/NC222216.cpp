#include <bits/stdc++.h>
using namespace std;
/*双指针好题,*/
const int maxn = 3e7 + 5;
const int mod = 19980829;
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