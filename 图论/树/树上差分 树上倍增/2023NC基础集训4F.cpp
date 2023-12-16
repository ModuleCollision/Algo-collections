/* 求二叉树固定位置节点的先序遍历顺序:

1. 初始化贡献为1
2. 从根节点至目标节点搜索,如果在右子树加上左子树的大小 + 1 , 在左子树则 + 1,接着移动当前点 直到到达搜索点 */



/* 求二叉树固定位置节点的中序遍历顺序:

1. 初始化贡献为1
2. 从根节点至目标节点搜索,如果在左子树只移动不算贡献,若在右子树则先移动, 再将 1 + 当前节点左兄弟子树的大小贡献中
3. 答案为贡献 + 当前节点的左子树大小
*/

/* 求二叉树固定位置节点的后序遍历顺序:
1. 初始化为1
2. 从根节点至目标节点搜索, 如果在右子树则贡献 + 1, 若在左子树则将 1 + 右子树的大小算入贡献中
3.答案为n - 贡献 + 1 */
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

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
     i64 k, q; std::cin >> k >> q;
     i64 n = (1 << k);
    auto lowbit = [&]( i64 x) ->  i64 {
        return x & -x;
    };
    auto sz = [&]( i64 x)-> i64{
        if (not x)return 0;
        return (lowbit(x) << 1) - 1;
    };
    auto lch = [&]( i64 x)-> i64{
         i64 cur = x - (lowbit(x) >> 1);
        if (lowbit(x) == 1)return 0;
        return cur;
    };
    auto rch = [&]( i64 x)-> i64 {
         i64 cur = x + (lowbit(x) >> 1);
        if (not(cur >= 1 and cur <= n))return 0;
        return cur;
    };
    auto pre = [&]( i64 x) {
         i64 root = n;
         i64 ret = 1;
        while (root != x) {
            ++ret;
            if (x < root) {
                root = lch(root);
            } else {
                ret += sz(lch(root));
                root = rch(root);
            }

        }
        return ret;
    };
    auto mid = [&]( i64 x) {
         i64 ret = 1;
         i64 root = n;
        if (x == n) {
            return n;
        }
        while (root != x) {
            if (x < root) {
                root = lch(root);
            } else {
                ret++;
                ret += sz(lch(root));
                root = rch(root);
            }
        }
        ret += sz(lch(root));
        return ret;
    };
    auto suf = [&]( i64 x) {
         i64 ret = 1;
         i64 root = n;
        while (root != x) {
            ++ret;
            if (x < root) {
                ret += sz(rch(root));
                root = lch(root);
            } else {
                root = rch(root);
            }
        }
        return n - ret + 1;
    };
    while (q--) {
         i64 x; std::cin >> x;
        cout << pre(x) << " " << mid(x) << " " << suf(x) << endl;
    }
}
signed main() {
    solve();
}

/*先序遍历 d -> l -> r*/
/*中序遍历 l -> d -> r*/
/*后序遍历 l -> r -> d*/
/*注意 : 后序遍历序列翻转等价于做 d -> r -> l 遍历得到的序列*/