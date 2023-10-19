class Solution {
public:
	typedef long long ll;
	long long maximumSumOfHeights(vector<int>& maxHeights) {
		ll n = maxHeights.size();
		vector<ll>st1(n + 5, 0); ll hed = 1, tal = 0;
		vector<ll>st2(n + 5, 0);//双向单调栈
		ll w = 0;
		vector<ll>pre(n + 1, 0), suf(n + 1, 0);
		for (ll i = 0; i < n; i++) {
			while (hed <= tal and maxHeights[st1[tal]] >= maxHeights[i]) {
				ll cur = st1[tal];
				tal--;
				ll f = hed <= tal ? st1[tal] : -1;
				ll d = cur - f;
				w -= d * maxHeights[cur];
			}
			ll f = hed <= tal ? st1[tal] : -1;
			ll d = i - f; w += d * maxHeights[i]; st1[++tal] = i;
			pre[i] = w;
		}
		w = 0; hed = 1, tal = 0;
		for (ll i = n - 1; i >= 0; i--) {
			while (hed <= tal and maxHeights[st2[tal]] >= maxHeights[i]) {
				ll cur = st2[tal];
				tal--;
				ll f = hed <= tal ? st2[tal] : n;
				ll d = f - cur;
				w -= d * maxHeights[cur];
			}
			ll f = hed <= tal ? st2[tal] : n;
			ll d = f - i; w += d * maxHeights[i]; st2[++tal] = i;
			suf[i] = w;
		}
		long long ans = 0;
		for (ll i = 0; i <= n - 1; i++) {
			ans = max(ans, (long long)((long long)pre[i] + (long long)suf[i] - maxHeights[i]));
		}
		return ans;
	}
};