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
	vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
		vector<pair<array<int, 3>, char>>st1;
		vector<pair<array<int, 2>, char>>st;
		int n = positions.size();
		for (int i = 0; i < n; i++) {
			st1.push_back({{positions[i], healths[i], i}, directions[i]});
		}
		std::sort(st1.begin(), st1.end(), [&](auto s, auto t)->bool{
			return s.first[0] < t.first[0];
		});
		for (auto c : st1) {
			st.push_back({{c.first[1], c.first[2]}, c.second});
		}
		vector<pair<array<int, 2>, char>>w;
		for (int i = 0; i < n; i++) {
			if (w.size()) {
				if (w.back().second == 'R' and st[i].second == 'L') {
					while (w.size()) {
						if (not (w.back().second == 'R' and st[i].second == 'L')) {
							break;
						} else {
							if (w.back().first[0] < st[i].first[0]) {
								st[i].first[0] -= 1;
								w.pop_back();
							} else if (w.back().first[0] == st[i].first[0]) {
								w.back().first[0] -= 1; st[i].first[0] = 0; w.pop_back();
								break;
							} else {
								w.back().first[0] -= 1; st[i].first[0] = 0; break;
							}
						}
					}
					if (st[i].first[0])w.push_back({{st[i].first[0], st[i].first[1]}, st[i].second});
				} else {
					w.push_back({{st[i].first[0], st[i].first[1]}, st[i].second});
				}
			} else {
				w.push_back({{st[i].first[0], st[i].first[1]}, st[i].second});
			}
		}
		vector<pair<int, int>>ans;
		for (auto c : w) {
			if (c.first[0])ans.push_back({c.first[0], c.first[1]});
		}
		sort(ans.begin(), ans.end(), [&](auto s, auto t) {
			return s.second < t.second;
		});
		vector<int>f;
		for (auto c : ans) {
			f.push_back(c.first);
		}
		return f;
	}
};