
class Solution {
public:
	typedef long long ll;
	const ll mod = 1e9 + 7;
	int maximumScore(vector<int>& nums, int k) {
		int n = nums.size(); vector<int>p(n + 5, 0); for (int i = 1; i <= n; i++)p[i] = nums[i - 1];
		vector<int>val(n + 5, 0);
		for (int i = 1; i <= n; i++) {
			int cur = p[i];
			for (int j = 2; j <= sqrt(cur); j++) {
				if (cur % j == 0) {
					while (cur % j == 0)cur /= j;
					val[i]++;
				}
			}
			if (cur > 1)val[i]++;
		}

		vector<int>q(4 * n + 5, 0);
		int hed = 1, tal = 0;
		vector<int>rt(n + 1, n + 1);
		vector<int>lt(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			while (hed <= tal and val[q[tal]] < val[i]) {
				rt[q[tal]] = i;
				tal--;
			}
			if (hed <= tal)lt[i] = q[tal];
			q[++tal] = i;
		}
		vector<ll>idx(n + 1);
		iota(idx.begin() + 1, idx.begin() + 1 + n, 1);
		std::sort(idx.begin() + 1, idx.begin() + 1 + n, [&](int x, int y)->bool{
			return p[x] > p[y];
		});
		ll ans = 1;
		auto ksm = [&](ll x, ll y) {
			ll ret = 1;
			while (y) {
				if (y & 1)ret = ret * x % mod;
				x = x * x % mod;
				y >>= 1;
			}
			return ret % mod;
		};
		for (int i = 1; i <= n; i++) {
			int id = idx[i];
			int tot = (ll)(id - lt[id]) * (rt[id] - id);
			ans = ans % mod * ksm((ll)p[id], (ll)min(k, tot)) % mod;
			k -= min(k, tot);
			if (not k)break;
		}
		return (int)ans % mod;
	}
};