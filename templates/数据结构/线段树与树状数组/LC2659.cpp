/*树状数组 + 模拟*/
/*本质上移动操作可以看作在环上操作*/
class Solution {
public:
	long long countOperationsToEmptyArray(vector<int>& nums) {
		int n = nums.size();
		vector<int>tr(n + 5, 0);
		pair<int, int>t[n + 5];
		for (int i = 1; i <= n; i++) {
			t[i] = {nums[i - 1], i};
		}
		std::sort(t + 1, t + 1 + n, [&](pair<int, int> x, pair<int, int>y)->bool{
			return x.first < y.first;
		});
		auto lowbit = [&](int x) {
			return x & -x;
		};
		auto add = [&](int v, int id) {
			for (; id <= n; id += lowbit(id)) {
				tr[id] += v;
			}
		};
		auto query = [&](int id) {
			int ret = 0;;
			for (; id >= 1; id -= lowbit(id)) {
				ret += tr[id];
			}
			return ret;
		};
		long long ret = 0, now = 0;
		for (int i = 1; i <= n; i++) {
			int x = t[i].first, y = t[i].second;
			if (y < now) {
				ret += n - now;
				ret -= query(n) - query(now);
				now = 0;
			}
			ret += y - now;
			ret -= query(y) - query(now);
			now = y;
			add(1, now);
		}
		return ret;
	}
};