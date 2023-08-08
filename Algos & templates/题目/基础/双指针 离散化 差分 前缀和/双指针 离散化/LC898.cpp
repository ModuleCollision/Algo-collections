class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size(); std::set<int>ans;
        vector<pair<int, int>>suf;
        for (int i = n - 1; i >= 0; i--) {
            suf.push_back({i, arr[i]});
            int cur = arr[i], k = 0;
            suf[0].second |= cur;
            ans.insert(suf[0].second);
            for (int j = 1; j < suf.size(); j++) {
                suf[j].second |= cur;
                ans.insert(suf[j].second);
                if (suf[j].second == suf[k].second) {
                    suf[k].first = suf[j].first;
                } else {
                    suf[++k] = suf[j];
                }
            }
            suf.resize(k + 1);
        }
        return ans.size();
    }
};