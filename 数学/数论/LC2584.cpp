class Solution {
public:
    typedef long long ll;
    int findValidSplit(vector<int> &nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int lim = mx + 3;
        vector<int>son(lim + 5, 0); int n = nums.size();
        vector<int>st[n + 5];
        for (int i = 2; i <= lim; i++) {
            if (not son[i]) {
                son[i] = i;
                for (int j = i + i; j <= lim; j += i) {
                    if (not son[j])son[j] = i;
                }
            }
        }
        unordered_map<ll , ll>cnt, tot;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (x == 1) {
                st[i].push_back(1); tot[1]++ ; continue;
            }
            while (x != 1) {
                int las = son[x];
                while (x % las == 0) {
                    x /= las;
                }
                st[i].push_back(las); tot[las]++;
            }
        }
        ll cur = tot.size();
        for (ll i = 0; i < n - 1; i++) {
            for (auto s : st[i]) {
                cnt[s] ++;
                if (cnt[s] == 1) {
                    cur--;
                }
                if (cnt[s] == tot[s])cur++;//出现的质数全部出现在分割点左半部
            }
            if (cur == tot.size())return i;

        }
        return -1;
    }
};