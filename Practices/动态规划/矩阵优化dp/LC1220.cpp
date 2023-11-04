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
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
class Solution {
public:
    int countVowelPermutation(int n) {
        i64 res = 0;
        auto mul = [&](vector<vector<i64>>&x, vector<vector<i64>>&y) {
            vector ret(5, vector<i64>(5, 0));
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    i64 v = 0;
                    for (int k = 0; k < 5; k++) {
                        v = (v % mod + x[i][k] % mod * y[k][j] % mod) % mod;
                    }
                    ret[i][j] = v % mod;
                }
            }
            return ret;
        };
        auto mat_ksm = [&](i64 y) {
            vector<vector<i64>>w = {
                {0, 1, 1, 0, 1},
                {1, 0, 1, 0, 0},
                {0, 1, 0, 1, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 1, 0},
            };
            vector ret(5, vector<i64>(5, 0));
            for (int i = 0; i < 5; i++)ret[i][0] = 1;
            while (y) {
                if (y & 1)ret = mul(w, ret);
                w = mul(w, w);
                y >>= 1;
            }
            return ret;
        };
        auto ans = mat_ksm(n - 1);
        for (int i = 0; i < 5; i++) {
            res = (res % mod + ans[i][0]) % mod;
        }
        return res % mod;
    }
};