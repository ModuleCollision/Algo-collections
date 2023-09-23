class Solution {
public:
    // 把字符串二进制转换成十进制数

    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        auto get = [&](string cnt) {
            int sum = 0;
            reverse(cnt.begin(), cnt.end());
            for (int i = 0; i < cnt.size(); i++) {
                sum += ((cnt[i] - '0') << i);
            }
            return sum;
        };
        std::unordered_map<int, vector<int>>sk;
        vector<vector<int>>ans;
        for (int l = 0; l < s.size(); l++) {
            for (int len = 1; len <= 31 and l + len - 1 < s.size(); len++) {
                int cur = get(s.substr(l, len));
                if (not sk.count(cur) or sk[cur][1] - sk[cur][0] >= len) {
                    sk[cur] = vector<int> {l, l + len - 1};
                }
            }
        }
        for (auto query : queries) {
            int val = query[0] ^ query[1];
            if (not sk.count(val))ans.push_back(vector<int> { -1, -1});
            else ans.push_back(sk[val]);
        }
        return ans;
    }
};