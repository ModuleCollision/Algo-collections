class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size();
        vector<pair<int, int>>suf;
        pair<int, int>ans;
        ans.first = ans.second = -1; int cur = 0x3f3f3f3f;
        for (int i = n - 1; i >= 0; i--) {
            suf.push_back({i, arr[i]});
            int k = 0;
            suf[0].second &= arr[i];
            for (int j = 1; j < suf.size(); j++) {
                suf[j].second |= arr[i];
                if (suf[j].second == suf[k].second) {
                    suf[k].first = suf[j].first;
                } else {
                    suf[++k] = suf[j];
                }
            }
            suf.resize(k + 1);
            for (int j = 0; j <= k; j++) {
                if (abs(suf[j].second - target) < cur) {
                    cur = abs(suf[j].second - target);
                }
            }
        }
        return cur;
    }
};