// Time:  O(m * n)
// Space: O(m + n)

// mono stack, optimized from solution2
class Solution {
public:
    vector<vector<int>> seePeople(vector<vector<int>>& heights) {
        vector<vector<int>> result(size(heights), vector<int>(size(heights[0])));
        const auto& count = [](int h, vector<int> *stk) {
            int cnt = 0;
            while (!empty(*stk) && stk->back() < h) {
                stk->pop_back();
                ++cnt;
            }
            if (!empty(*stk)) {
                ++cnt;
            }
            if (empty(*stk) || stk->back() != h) {
                stk->emplace_back(h);
            }
            return cnt;
        };

        for (int i = 0; i < size(heights); ++i) {
            vector<int> stk;
            for (int j = size(heights[0]) - 1; j >= 0; --j) {
                result[i][j] += count(heights[i][j], &stk);
            }
        }
        for (int j = 0; j < size(heights[0]); ++j) {
            vector<int> stk;
            for (int i = size(heights) - 1; i >= 0; --i) {
                result[i][j] += count(heights[i][j], &stk);
            }
        }
        return result;
    }
};

// Time:  O(m * n)
// Space: O(m + n)
// mono stack
class Solution2 {
public:
    vector<vector<int>> seePeople(vector<vector<int>>& heights) {
        vector<vector<int>> result(size(heights), vector<int>(size(heights[0])));
        const auto& count = [](const auto& height, int i, vector<int> *stk) {
            int cnt = 0;
            while (!empty(*stk) && height(stk->back()) < height(i)) {
                stk->pop_back();
                ++cnt;
            }
            if (!empty(*stk)) {
                ++cnt;
            }
            if (!empty(*stk) && height(stk->back()) == height(i)) {
                stk->pop_back();
            }
            stk->emplace_back(i);
            return cnt;
        };

        for (int i = 0; i < size(heights); ++i) {
            const auto& height = [&](int x) {
                return heights[i][x];
            };
            vector<int> stk;
            for (int j = size(heights[0]) - 1; j >= 0; --j) {
                result[i][j] += count(height, j, &stk);
            }
        }
        for (int j = 0; j < size(heights[0]); ++j) {
            const auto& height = [&](int x) {
                return heights[x][j];
            };
            vector<int> stk;
            for (int i = size(heights) - 1; i >= 0; --i) {
                result[i][j] += count(height, i, &stk);
            }
        }
        return result;
    }
};

// Time:  O(m * n)
// Space: O(m + n)
// mono stack
class Solution3 {
public:
    vector<vector<int>> seePeople(vector<vector<int>>& heights) {
        vector<vector<int>> result(size(heights), vector<int>(size(heights[0])));
        const auto& count = [](const auto& height, int i, vector<int> *stk, const auto& increase) {
            while (!empty(*stk) && height(stk->back()) < height(i)) {
                increase(stk->back()); stk->pop_back();
            }
            if (!empty(*stk)) {
                increase(stk->back());
            }
            if (!empty(*stk) && height(stk->back()) == height(i)) {
                stk->pop_back();
            }
            stk->emplace_back(i);
        };

        for (int i = 0; i < size(heights); ++i) {
            const auto& height = [&](int x) {
                return heights[i][x];
            };
            const auto& increase = [&](int x) {
                ++result[i][x];
            };
            vector<int> stk;
            for (int j = 0; j < size(heights[0]); ++j) {
                count(height, j, &stk, increase);
            }
        }
        for (int j = 0; j < size(heights[0]); ++j) {
            const auto& height = [&](int x) {
                return heights[x][j];
            };
            const auto& increase = [&](int x) {
                ++result[x][j];
            };
            vector<int> stk;
            for (int i = 0; i < size(heights); ++i) {
                count(height, i, &stk, increase);
            }
        }
        return result;
    }
};
