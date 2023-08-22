class Solution {
public:
    typedef long long ll;
    const ll mod = 1e9 + 7;
    ll dp[1005][15];
    int countSteppingNumbers(string low, string high) {
        for (ll i = 0; i <= 9; i++)dp[1][i] = 1;
        for (ll i = 2; i <= 100; i++) {
            for (ll j = 0; j <= 9; j++) {
                for (ll k = 0; k <= 9; k++) {
                    if (abs(k - j) == 1)dp[i][j] = (dp[i][j] % mod + dp[i - 1][k]) % mod;
                }
            }
        }
        ll pre = 1;
        for (ll i = low.size() - 1; i >= 0; i--) {
            ll cur = low[i] - '0';
            cur -= pre; bool f = 1;
            if (cur < 0)cur = (cur + 10) % 10, pre = 1, f = 0;
            low[i] = cur + '0';
            if (f)break;
        }
        reverse(low.begin(), low.end());
        while (low.back() == '0')low.pop_back();
        reverse(low.begin(), low.end());
        cout << low << endl;
        auto cal = [&](string t) {
            reverse(t.begin(), t.end());
            ll res = 0; ll pre = -10; ll len = t.size() - 1;
            for (ll i = len; i >= 0; i--) {
                ll cur = t[i] - '0';
                for (ll j = (i == len); j < cur; j++) {
                    if ((abs(j - pre) == 1) or i == len)res = (res % mod + dp[i + 1][j]) % mod;
                }
                if (abs(cur - pre) != 1 and pre != -10)break;
                pre = cur;
                if (not i)res++;
            }
            for (ll i = 1; i <= len; i++) {
                for (ll j = 1; j <= 9; j++) {
                    res = (res % mod + dp[i][j]) % mod;
                }
            }
            return res % mod;
        };
        ll ans = (cal(high) - cal(low) % mod + mod) % mod;
        return (int)ans;
    }
};


class Solution {
public:
    typedef long long ll;
    const ll mod = 1e9 + 7;

    int countSteppingNumbers(string low, string high) {
        auto cal = [&] (string & s) {
            ll n = s.size();
            ll dp[n + 5][10]; memset(dp, -1, sizeof(dp));
            function<ll(ll, ll, bool, bool)>dfs = [&](ll idx, ll pre, bool isnum, bool islimit) {
                if (idx == n) {
                    return (ll)isnum;
                }
                if ((not islimit) and isnum and dp[idx][pre] != -1)return dp[idx][pre];
                ll res = 0;
                if (not isnum)res = (res % mod + dfs(idx + 1, pre, false, false)) % mod;
                ll low = isnum ? 0 : 1; ll up = islimit ? s[idx] - '0' : 9;
                for (ll d = low; d <= up; d++) {
                    if ((not isnum) or abs(d - pre) == 1) {
                        res = (res % mod + dfs(idx + 1, d, true, d == up and islimit)) % mod;
                    }
                }
                if (not islimit and isnum)dp[idx][pre] = res % mod;
                return res % mod;
            };
            return dfs(0, 0, false, true);
        };
        auto valid = [&](string s) {
            for (int i = 1; i < s.size(); i++) {
                if (abs((int)s[i] - (int)s[i - 1]) != 1)return false;
            }
            return true;
        };
        return (int)((cal(high) - cal(low)) % mod + mod + valid(low)) % mod;
    }
};