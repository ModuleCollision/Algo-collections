class Solution {
public:
    long long beautifulSubstrings(string s, int K) {
        // 判断字符 c 是不是元音
        auto check = [&](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int n = s.size();

        // valid 里保存了所有满足 w^2 mod k = 0 的 w
        vector<int> valid;
        for (int rem = 0; rem < K; rem++) if (rem * rem % K == 0) valid.push_back(rem);

        long long ans = 0;
        unordered_map<int, unordered_map<int, int>> mp;
        // 用长度为 0 的前缀初始化哈希表
        mp[0][0] = 1;
        // det：前缀中元音减辅音的值
        // cnt：前缀中元音的数量
        int det = 0, cnt = 0;
        // 枚举子串右端点
        for (int i = 0; i < n; i++) {
            if (check(s[i])) det++, cnt++;
            else det--;
            // 枚举 w
            for (int rem : valid) {
                int t = (cnt - rem + K) % K;
                if (mp[det].count(t)) ans += mp[det][t];
            }
            // 用以 i 为结尾的前缀更新哈希表
            mp[det][cnt % K]++;
        }
        return ans;
    }
};