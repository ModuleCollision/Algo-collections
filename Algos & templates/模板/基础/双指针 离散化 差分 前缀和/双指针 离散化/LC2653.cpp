class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>ans;
        std::map<int, int>st;
        auto add = [&](ll v) {
            st[v]++;
        };
        auto del = [&](ll v) {
            st[v]--;
            if (not st[v]) {
                st.erase(v);
            }
        };
        for (int i = 0; i < k - 1; i++) {
            add(nums[i]);
        }
        for (ll l = -1, r = k - 1; r < n; r++) {
            ll tmp = x;
            add(nums[r]);
            if (l >= 0)del(nums[l]);
            l++;
            for (auto [a, b] : st) {
                if (tmp > b) {
                    tmp -= b; continue;
                } else if (tmp <= b) {
                    ans.push_back(a);
                    tmp -= min(tmp, b); break;
                }
            }
            if (tmp) {
                ans.push_back(0);
            }
        }
        return ans;
    }
};