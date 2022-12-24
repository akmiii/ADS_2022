// Submit a solution for J-Who has a big Family?
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<bool> used;
int cnt;

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		int vu = g[v][i];
		if (!used[vu]) {
			if (g[vu].size() > g[v].size()) cnt++;
			dfs(vu);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	used.resize(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
	}

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}