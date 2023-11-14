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
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
void solve() {
    ll k, q; std::cin >> k >> q;
    ll n = (1 << k);
    auto lowbit = [&](ll x) -> ll {
        return x & -x;
    };
    auto sz = [&](ll x)->ll{
        if (not x)return 0;
        return (lowbit(x) << 1) - 1;
    };
    auto lch = [&](ll x)->ll{
        ll cur = x - (lowbit(x) >> 1);
        if (lowbit(x) == 1)return 0;
        return cur;
    };
    auto rch = [&](ll x)->ll {
        ll cur = x + (lowbit(x) >> 1);
        if (not(cur >= 1 and cur <= n))return 0;
        return cur;
    };
    auto pre = [&](ll x) {
        ll root = n;
        ll ret = 1;
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
    auto mid = [&](ll x) {
        ll ret = 1;
        ll root = n;
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
    auto suf = [&](ll x) {
        ll ret = 1;
        ll root = n;
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
        ll x; std::cin >> x;
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