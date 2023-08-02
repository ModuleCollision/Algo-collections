class Solution {
public:
    typedef long long ll;
    const ll mod = 1e9 + 7;
    int sumOfPower(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        ll n = nums.size();
        auto ksm = [&](ll a, ll b) {
            ll ret = 1;
            while (b) {
                if (b & 1)ret = ret % mod * a % mod;
                a = a % mod * a % mod;
                b >>= 1;
            }
            return ret;
        };
        vector<ll>suf(n + 5, 0);
        for (ll i = n - 1; i >= 0; i--) {
            suf[i] = (suf[i] % mod + suf[i + 1]) % mod;
            suf[i] += ksm(2, i) % mod * nums[i] % mod * nums[i] % mod;
            suf[i] %= mod;
        }
        ll ans 
        for (ll i = 0; i < n; i++) {
            ans = (ans % mod + ksm(nums[i], 3) % mod) % mod;
        }
        auto inv = [&](ll x) {
            return ksm(x, mod - 2) % mod;
        };
        for (ll i = 0; i < n - 1; i++) {
            ll tmp = suf[i + 1] % mod  * inv(ksm(2, i + 1) % mod)  % mod;
            ans = (ans % mod + nums[i] % mod * tmp) % mod;
        }
        return ans;
    }
};