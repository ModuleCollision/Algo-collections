

/*多组Test下使用封装数据结构, 在函数中开对象,避免暴力清空数组造成时间浪费*/

/*STL: 数据结构 cin cout function类 lowerbound builtin max min accumulate iota stoi atoi等函数需要加上std,避免命名空间污染*/

/*数学先打表, 后对拍, 图论只会暴力就bitset搞*/

/*300兆字节 1- 2 秒*/

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
constexpr i64 mod = 1e9 + 7;
constexpr i64 maxn = 1e7 + 500;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


struct Matrix {
public:
    i64 n; std::vector<std::vector<i64>>a;
    Matrix(i64 len = 4): n(len), a(len) {
        for (i64 i = 0; i < len; i++) {
            a[i].assign(len, 0);
        }
    }
    friend Matrix operator*(Matrix x, Matrix y) {
        i64 n = x.n;
        Matrix ret(n);
        for (i64 i = 0; i < n; i++) {
            for (i64 j = 0; j < n; j++) {
                for (i64 k = 0; k < n; k++) {
                    ret.a[i][j] = (ret.a[i][j] % mod + x.a[i][k] % mod * y.a[k][j] % mod) % mod;
                }
            }
        }
        return ret;
    }
    friend Matrix quickPower(Matrix x, i64 y) {
        Matrix ret(x.n);
        for (i64 i = 0; i < x.n; i++)ret.a[i][i] = 1;
        while (y) {
            if (y & 1)ret = ret * x;
            x = x * x;
            y >>= 1;
        }
        return ret;
    };
};
class Solution {
public:
    int countVowelPermutation(int n) {
        i64 res = 0;
        Matrix w(5);
        w.a = {
            {0, 1, 1, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 1, 0},
        };
        Matrix ret(5);
        for (i64 i = 0; i < 5; i ++)ret.a[i][0] = 1;
        auto ans = quickPower(w, n - 1);
        ans = ans * ret;
        for (int i = 0; i < 5; i++) {
            res = (res % mod + ans.a[i][0]) % mod;
        }
        return res % mod;
    }
};