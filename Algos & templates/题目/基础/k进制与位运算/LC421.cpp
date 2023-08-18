class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		int n = nums.size();
		int pre = 0;
		for (int k = 30; k >= 0; k--) {
			unordered_set<int>st;
			for (auto c : nums) {
				st.insert((c >> k));
			}
			int cur = pre * 2 + 1; bool f = 0;
			for (auto c : nums) {
				if (st.count((c >> k)^cur)) {
					f = 1; break;
				}
			}
			if (f)pre = cur;
			else pre = cur - 1;
		}
		return pre;
	}
};