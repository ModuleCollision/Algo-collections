class Solution {
public:
    typedef long long ll;
    vector<int> splitIntoFibonacci(string num) {
        vector<int>p;
        int len = num.size();
        function<bool(int, int, int)>dfs = [&](int idx, ll sum, int pre) {
            if (idx == len)return p.size() >= 3;
            ll cur = 0;
            for (int i = idx; i < len; i++) {
                if (i > idx and num[idx] == '0')break;
                cur = cur * 10 + num[i] - '0';
                if (cur > INT_MAX)break;
                if (p.size() >= 2) {//剪枝,意义在于接下来不可能再有符合的情况了
                    if (cur < sum)continue;
                    else if (cur > sum)break;//当前数目大于2才有判断的必要
                }
                p.push_back(cur);
                bool f = dfs(idx + 1, cur + pre, cur);
                if (f)return true;//搜索到了一种符合的情况才返回true
                p.pop_back();
            }
            return false;
        };
        dfs(0, 0, 0);
        return p;
    }
};