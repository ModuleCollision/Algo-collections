class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k) {
        unordered_set<int>ban;
        for (auto c : banned)ban.insert(c);
        std::set<int>sets[2];//分别维护可以达到的奇偶下标
        for (int i = 0; i < n; i++) {
            if (i != p and !ban.count(i)) {
                sets[i % 2].insert(i);
            }
        }
        sets[0].insert(n);
        sets[1].insert(n);
        vector<int>ans(n, -1);
        vector<int>q = {p};
        for (int step = 0; !q.empty(); ++step) {
            vector<int> nq;
            for (int i : q) {
                ans[i] = step;
                // 从 mn 到 mx 的所有位置都可以翻转到
                int mn = max(i - k + 1, k - i - 1);
                int mx = min(i + k - 1, n * 2 - k - i - 1);
                auto &s = sets[mn % 2];
                for (auto it = s.lower_bound(mn); *it <= mx; it = s.erase(it))
                    nq.push_back(*it);
            }
            q = move(nq);
        }
        return ans;
    }
};