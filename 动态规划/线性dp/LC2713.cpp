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

class Solution {
public:
	
	int maxIncreasingCells(vector<vector<int>>& mat) {
		int n = mat.size(); int m = mat[0].size();
		vector<int>r(n + 5, -inf), c(m + 5, -inf);
		std::map<int, vector<pair<int, int>>>mp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)mp[mat[i][j]].push_back({i, j});
		}
		int ans = -inf;
		for (auto [x, y] : mp) {
			vector<pair<int, int>>vec, ver;
			for (auto p : y) {
				int t = max({1, r[p.first] + 1, c[p.second] + 1});
				ans = max(ans, t);
				ver.push_back({p.first, t});
				vec.push_back({p.second, t});
			}
			for (auto p : vec) {
				c[p.first] = max(c[p.first], p.second);
			}
			for (auto p : ver) {
				r[p.first] = max(r[p.first], p.second);
			}
		}
		return ans;
	}
};