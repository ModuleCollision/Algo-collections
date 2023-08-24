class Solution {
public:
	string minInteger(string num, int k) {
		int n = num.size();
		num = " " + num;
		vector<int>tr(n + 5, 0);
		auto add = [&](int idx, int v) {
			for (; idx <= n; idx += (idx & -idx))tr[idx] += v;
		};
		auto query = [&](int idx) {
			int ret = 0;
			for (; idx >= 1; idx -= (idx & -idx))ret += tr[idx];
			return ret;
		};
		vector<bool>vis(n + 5, false); vector<vector<int>>idx(15);
		vector<int>id(15, 0);
		string res;
		for (int i = 1; i <= n; i++) {
			idx[num[i] - '0'].push_back(i);
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i])continue;
			int cur = num[i] - '0'; bool f = 0;
			for (int j = 0; j < cur; j++) {
				while (id[j] < idx[j].size() and idx[j][id[j]] < i)id[j]++;
				if (id[j] == idx[j].size())continue;
				int suf = idx[j][id[j]];
				int q = query(suf);
				if (suf - q - 1 <= k) {
					k -= (suf - q - 1);
					cout << suf - q - 1 << endl;
					id[j]++;
					vis[suf] = true;
					add(suf, 1); i--;
					res += (j + '0');
					f = true;
				}
				if (f)break;
			}
			if (not f) {
				add(i, 1);
				vis[i] = true;
				res += (num[i]);
			}
		}
		return res;
	}
};