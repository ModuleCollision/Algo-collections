class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), pre = nums[0], cnt1 = 0;
        function<int(int , int)>gcd = [&](int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
        };
        for (int i = 1; i < n; i++) {
            pre = gcd(pre, nums[i]);
            cnt1 += nums[i] == 1;
        }
        if (pre > 1) {
            return -1;
        }
        if (cnt1)return n - cnt1;
        int min_size = 0x3f3f3f3f;
        vector<pair<int, int>>g;
        for (int i = 0; i < n; i++) {
            g.push_back({nums[i], i});
            int j = 0;
            for (int k = 0; k < g.size(); k++) {
                g[k].first = gcd(g[k].first, nums[i]);
                if (g[k].first == g[j].first) {
                    g[j].second = g[k].second;
                } else {
                    g[++j] = g[k];
                }
            }
            g.resize(j + 1);
            if (g[0].first == 1) {
                min_size = min(min_size, i - g[0].second);
            }
        }
        return min_size + n - 1;
    }
};