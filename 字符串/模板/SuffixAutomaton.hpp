

struct SuffixAutomaton {
public:
	struct state {
		int len; int link; int sz;
		int nxt[30];
	};
	std::vector<state>st;
	int tot1, last = 1;
	SuffixAutomaton(int n): st(n * 2 + 2) {
		st[1].len = 0;
		st[1].link = 0;
		tot1 = 1; last = 1;
	}
	void extend(char t) {
		int cur = ++tot1;
		st[cur].sz = 1;
		st[cur].len = st[last].len + 1;
		int p = last; int c = t - 'a';
		while (p and not st[p].nxt[c]) {
			st[p].nxt[c] = cur;
			p = st[p].link;
		}
		if (not p)st[cur].link = 1;
		else {
			int q = st[p].nxt[c];
			if (st[p].len + 1 == st[q].len) {
				st[cur].link = q;
			} else {
				int clone = ++tot1;
				st[clone].len = st[p].len + 1;
				for (int i = 0; i <= 25; i++)st[clone].nxt[i] = st[q].nxt[i];
				st[clone].link = st[q].link;
				while (p and st[p].nxt[c] == q) {
					st[p].nxt[c] = clone; p = st[p].link;
				}
				st[q].link = st[cur].link = clone;
			}
		}
		last = cur;
	}
};