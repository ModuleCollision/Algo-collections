#include<bits/extc++.h>

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;

constexpr i64 mod = 1e9 + 7;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
class Solution {
public:



    int sumOfPower(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        i64 n = nums.size();
        auto ksm = [&](i64 a, i64 b) {
            i64 ret = 1;
            while (b) {
                if (b & 1)ret = ret % mod * a % mod;
                a = a % mod * a % mod;
                b >>= 1;
            }
            return ret;
        };
        vector<i64>suf(n + 5, 0);
        for (i64 i = n - 1; i >= 0; i--) {
            suf[i] = (suf[i] % mod + suf[i + 1]) % mod;
            suf[i] += ksm(2, i) % mod * nums[i] % mod * nums[i] % mod;
            suf[i] %= mod;
        }
        i64 ans
        for (i64 i = 0; i < n; i++) {
            ans = (ans % mod + ksm(nums[i], 3) % mod) % mod;
        }
        auto inv = [&](i64 x) {
            return ksm(x, mod - 2) % mod;
        };
        for (i64 i = 0; i < n - 1; i++) {
            i64 tmp = suf[i + 1] % mod  * inv(ksm(2, i + 1) % mod)  % mod;
            ans = (ans % mod + nums[i] % mod * tmp) % mod;
        }
        return ans;
    }
};