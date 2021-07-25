// Time:  O(m^2 * (n + m))
// Space: O(m^2)

// Template from:
// https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/WeightedMatching.h
// Time:  O(N^2 * M)
// Space: O(N + M)
pair<int, vector<int>> hungarian(const vector<vector<int>> &a) {
	if (empty(a)) {
        return {0, {}};
    }
	int n = size(a) + 1, m = size(a[0]) + 1;
	vector<int> u(n), v(m), p(m), ans(n - 1);
	for (int i = 1; i < n; ++i) {
		p[0] = i;
		int j0 = 0;  // add "dummy" worker 0
		vector<int> dist(m, numeric_limits<int>::max()), pre(m, -1);
		vector<bool> done(m + 1);
		do {  // dijkstra
			done[j0] = true;
			int i0 = p[j0], j1, delta = numeric_limits<int>::max();
			for (int j = 1; j < m; ++j) {
                if (!done[j]) {
                    auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < dist[j]) {
                        dist[j] = cur, pre[j] = j0;
                    }
                    if (dist[j] < delta) {
                        delta = dist[j], j1 = j;
                    }
                }
            }
			for (int j = 0; j < m; ++j) {
				if (done[j]) {
                    u[p[j]] += delta, v[j] -= delta;
                } else {
                    dist[j] -= delta;
                }
			}
			j0 = j1;
		} while (p[j0]);
		while (j0) {  // update alternating path
			int j1 = pre[j0];
			p[j0] = p[j1], j0 = j1;
		}
	}
	for (int j = 1; j < m; ++j) {
        if (p[j]) {
            ans[p[j] - 1] = j - 1;
        }
    }
	return {-v[0], ans};  // min cost
}

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<vector<int>> cost(size(students), vector<int>(size(mentors)));
        for (int i = 0; i < size(students); ++i) {
            for (int j = 0; j < size(mentors); ++j) {
                cost[i][j] = -score(students[i], mentors[j]);
            }
        }
        return -hungarian(cost).first;
    }

private:
    int score(const vector<int>& s, const vector<int>& m) {
        int result = 0;
        for (int i = 0; i < size(s); ++i) {
            result += int(s[i] == m[i]);
        }
        return result;
    }
};
