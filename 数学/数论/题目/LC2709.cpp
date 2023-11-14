#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
bool vis[maxn]; vector<int>p[maxn]; bool f = false;
void init() {
	if (f)return; f = 1;
	for (int i = 2; i <= 1e5; i++) {
		if (not vis[i]) {
			p[i].push_back(i);
			for (int j = i + i; j <= 1e5; j += i)p[j].push_back(i), vis[j] = 1;
		}
	}
}
class Solution {
public:

	bool canTraverseAllPairs(vector<int>& nums) {
		init();


		int n = nums.size();
		int mx = 0; for (int i = 0; i < n; i++)mx = max(mx, nums[i]);
		vector<int>fa(n + mx + 5, 0);
		auto find = [&](int x) {
			while (x != fa[x])x = fa[x] = fa[fa[x]];
			return x;
		};
		auto merge = [&](int x, int y) {
			x = find(x), y = find(y); if (x == y)return;
			fa[x] = y;
		};
		for (int i = 1; i <= n + mx; i++)fa[i] = i;
		for (int i = 1; i <= n; i++) {
			int cur = nums[i - 1];
			for (auto s : p[cur]) {
				int x = find(i), y = find(s + n);
				if (x == y)continue;
				merge(x, y);
			}
		}
		std::set<int>st;
		for (int i = 1; i <= n; i++)st.insert(find(i));
		return st.size() == 1;
	}
};