struct cmp {
    bool operator()(const pair<int, int>&x, const pair<int, int>&y)const {
        if (x.first != y.first)return x.first > y.first;
        return x.second > y.second;
    }
};


class Solution {
public:
    /*模拟自平衡排序二叉树*/
    /*按照键值排序，取最大键值*/
    /*支持删除修改查询*/
    //1. cmp重载规则不允许出现等号
    //2. 不允许引入外部变量定义比较规则
    //3. 多个变量排序规则一致
    int minLengthAfterRemovals(vector<int>& nums) {
        std::set<pair<int, int>, greater<>>st;
        //std::set<pair<int, int>, cmp>st; 也可
        std::unordered_map<int, int>cnt;
        for (auto c : nums)cnt[c]++;
        for (auto [a, b] : cnt)st.insert({b, a});
        reverse(nums.begin(), nums.end());
        auto f = [&](pair<int, int> x, pair<int, int> y)->bool{
            return x.first < y.first;
        };
        if (st.size() > 1) {
            for (auto x : nums) {
                if (cnt[x] == 0)continue;
                st.erase(st.lower_bound({cnt[x], x}));
                //st.erase({cnt[x], x});也可以
                cnt[x]--;
                if (cnt[x] > 0)st.insert({cnt[x], x});
                auto p = st.begin();
                if (p->second == x) {
                    p = next(p);
                    if (p == st.end())break;
                }
                int a = p->first, b = p->second;
                st.erase(st.lower_bound({a, b}));
                if (a - 1 > 0) {
                    st.insert({a - 1, b});
                }
                cnt[b]--;
                if (st.size() <= 1)break;
            }
        }
        int ans = 0;
        for (auto itr : st)ans += itr.first;
        return ans;
    }
};