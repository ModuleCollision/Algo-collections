class Solution {
public:
    typedef long long ll;
    const ll mod = 1e9 + 7;
    int squareFreeSubsets(vector<int>& nums) {
        vector<ll>primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        const ll maxn = 10;
        auto check = [&](int x) {
            for (int i = 0; i < 10; i++) {
                if (x % (primes[i]*primes[i]) == 0)return false;
            }
            return true;
        };
        ll n = nums.size(); vector dp(n + 5, vector<ll>(1 << 12, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (1 << 10); j++) {
                dp[i][j] = dp[i - 1][j] % mod;
            }
            int x = nums[i - 1];
            if (not check(x))continue;
            ll msk = 0;
            for (int j = 0; j < 10; j++) {
                if (x % primes[j] == 0)msk |= (1 << j);
            }
            for (int j = 0; j < (1 << 10); j++) {
                if ((j & msk) == 0) {
                    dp[i][j | msk] = (dp[i][j | msk] % mod + dp[i - 1][j]) % mod;
                }
            }
        }
        ll ans = 0;
        for (int j = 0; j < (1 << 10); j++) {
            ans = (ans % mod + dp[n][j]) % mod;
        }
        ans = ((ans - 1) % mod + mod) % mod; return ans;
    }
};