class Solution {
public:
    int beautifulSubsets(vector<int> & nums, int k) {
        //在这里我们做分组dp,考虑每一个人对于其的贡献
        unordered_map<int, map<int, int>>groups;
        for (int x : nums) {
            ++groups[x % k][x];//维护对k同余的情况下每一个数的出现次数
        }
        int ans = 1;
        for (auto [_, g] : groups) {
            int m = g.size();
            vector<int>dp(m + 5, 0);
            auto it = g.begin();
            dp[0] = 1;
            dp[1] = 1 << (it->second);
            auto prev = it; it++;
            for (int i = 2; it != g.end(); it++, prev++) {
                if (it->first - (prev->first) == k) {
                    dp[i] = (dp[i - 1] + dp[i - 2] * ((1 << it->second) - 1));
                } else {
                    dp[i] = (dp[i - 1]) << (it->second);
                }
            }
            ans *= dp[m];
        }
        return ans - 1;
    }

};