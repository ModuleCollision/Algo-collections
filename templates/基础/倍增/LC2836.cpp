const int maxn = 2e5 + 5;
class Solution {
public:
	long long getMaxFunctionValue(vector<int>& receiver, long long k) {
		int n = receiver.size();
		int f[n + 5][36];
		long long w[n + 5][36];
		for (int i = 0; i < n; i++) {
			f[i][0] = receiver[i];
			w[i][0] = receiver[i];
		}
		for (int j = 1; j < 36; j++) {
			for (int i = 0; i < n; i++) {
				f[i][j] = f[f[i][j - 1]][j - 1];
				w[i][j] = w[i][j - 1] + w[f[i][j - 1]][j - 1];
			}
		}
		long long res = 0;
		for (int i = 0; i < n; i++) {
			long long ret = 0;
			int cur = i;
			for (int j = 0; j < 36; j++) {
				if ((k >> j) & 1) {
					ret += w[cur][j];
					cur = f[cur][j];
				}
			}
			res = max(res, ret + i);
		}
		return res;
	}
};