// Time:  O(mlogm + nlogn)
// Space: O(1)

// sort, greedy
class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(begin(horizontalCut), end(horizontalCut));
        sort(begin(verticalCut), end(verticalCut));
        int result = 0;
        for (int cnt_h = 1, cnt_v = 1; !empty(horizontalCut) || !empty(verticalCut); ) {
            if (empty(verticalCut) || (!empty(horizontalCut) && horizontalCut.back() > verticalCut.back())) {
                result += horizontalCut.back() * cnt_h; horizontalCut.pop_back();
                ++cnt_v;
            } else {
                result += verticalCut.back() * cnt_v; verticalCut.pop_back();
                ++cnt_h;
            }
        }
        return result;
    }
};

// Time:  O(mlogm + nlogn)
// Space: O(1)
// sort, greedy
class Solution2 {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(begin(horizontalCut), end(horizontalCut), greater<int>());
        sort(begin(verticalCut), end(verticalCut), greater<int>());
        int result = 0;
        for (int i = 0, j = 0; i < size(horizontalCut) || j < size(verticalCut); ) {
            if (j == size(verticalCut) || (i < size(horizontalCut) && horizontalCut[i] > verticalCut[j])) {
                result += horizontalCut[i++] * (j + 1);
            } else {
                result += verticalCut[j++] * (i + 1);
            }
        }
        return result;
    }
};

// Time:  O((m + n) * m^2 * n^2)
// Space: O(m^2 * n^2)
// memoization
class Solution3 {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<vector<vector<vector<int>>>> lookup(m, vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(n, -1))));
        const function<int (int, int, int, int)> memoization = [&](int x1, int y1, int x2, int y2) {
            static const int INF = numeric_limits<int>::max();

            if (x1 == x2 && y1 == y2) {
                return 0;
            }
            if (lookup[x1][y1][x2][y2] == -1) {
                int mn = INF;
                for (int x = x1; x + 1 <= x2; ++x) {
                    mn = min(mn, memoization(x1, y1, x, y2) + memoization(x + 1, y1, x2, y2) + horizontalCut[x]);
                }
                for (int y = y1; y + 1 <= y2; ++y) {
                    mn = min(mn, memoization(x1, y1, x2, y) + memoization(x1, y + 1, x2, y2) + verticalCut[y]);
                }
                lookup[x1][y1][x2][y2] = mn;
            }
            return lookup[x1][y1][x2][y2];
        };

        return memoization(0, 0, m - 1, n - 1);
    }
};
