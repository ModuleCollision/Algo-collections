class Solution {
public:
    typedef long long ll;
    vector<int> splitIntoFibonacci(string num) {
        int len = num.size(); vector<int>p;
        function<bool(int)>dfs = [&](int idx) {
            if (idx >= len) {
                //for (auto c : p)cout << c << endl;
                return p.size() >= 3;
            }
            ll cur = 0;
            for (int i = idx; i < len; i++) {
                if (i > idx and num[idx] == '0')break;
                cur = cur * 10 + num[i] - '0';
                if (cur >= (1ll << 31))break;
                if (p.size() >= 2) {
                    ll pre = (ll)p[p.size() - 1] + (ll)p[p.size() - 2];
                    if (cur < pre)continue;
                    else if (cur > pre)break;
                }
                p.push_back(cur);
                bool f = dfs(i + 1); if (f)return true;
                p.pop_back();
            }
            return false;
        };
        dfs(0); return p;
    }
};