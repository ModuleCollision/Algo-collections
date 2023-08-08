class Solution {
public:
	typedef double db;
	typedef long long ll;
	typedef long double lb;
	const ll maxn = 5e3 + 5;
	const ll inf = 0x3f3f3f3f3f3f3f3f;
	const ll mod = 1e9 + 7;
	long long continuousSubarrays(vector<int>& nums) {
		ll ans = 0;
		int n = nums.size(); std::map<int, int>cnt;
		auto add = [&](int v) {
			cnt[v]++;
		};
		auto del = [&](int v) {
			cnt[v]--;
			if (cnt[v] == 0)cnt.erase(v);
		};
		auto query = [&]()->bool{
			int x1 = cnt.begin()->first;
			auto s2 = --cnt.end();
			int x2 = s2->first;
			return x2 - x1 > 2;
		};
		for (int l = 0, r = 0; r < n; r++) {
			add(nums[r]);
			while (query()) {
				del(nums[l++]);
			}
			ans += (ll)(r - l + 1);
		}
		return ans;
	}
};