// Time:  O(h * p^2), p is the number of patterns
// Space: O(p^2)

// bitmask, backtracking, dp
class Solution {
public:
    int buildWall(int height, int width, vector<int>& bricks) {
        static const int MOD = 1e9 + 7;
        vector<int> patterns;
        unordered_set<int> lookup;
        backtracking(height, width, bricks, 0, 0, &lookup, &patterns);
        vector<vector<int>> adj(size(patterns));
        for (int i = 0; i < size(patterns); ++i) {
            for (int j = 0; j < size(patterns); ++j) {
                if (!(patterns[i] & patterns[j])) {
                    adj[i].emplace_back(j);
                }
            }
        }
        vector<vector<int>> dp = {vector<int>(size(patterns), 1), vector<int>(size(patterns), 0)};
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < size(patterns); ++j) {
                dp[(i + 1) % 2][j] = 0;
                for (const auto& k : adj[j]) {
                    dp[(i + 1) % 2][j] = (dp[(i + 1) % 2][j] + dp[i % 2][k]) % MOD;
                }
            }
        }
        return accumulate(cbegin(dp[(height - 1) % 2]), cend(dp[(height - 1) % 2]), 0,
                          [](const auto& total, const auto& x) {
                              return (total + x) % MOD;
                          });  // Time: O(p)
    }

private:
    void backtracking(
        int height, int width, const vector<int>& bricks,
        int total, int mask,
        unordered_set<int> *lookup,
        vector<int> *patterns) {

        if (lookup->count(mask)) {
            return;
        }
        lookup->emplace(mask);
        if (total >= width) {
            if (total == width) {
                patterns->emplace_back(mask ^ (1 << width));
            }
            return;
        }
        for (const auto& x : bricks) {
            backtracking(height, width, bricks, total + x, mask | (1 << (total + x)), lookup, patterns);
        }
    }
};

// Time:  O(p^3 * logh), p is the number of patterns, p may be up to 512
// Space: O(p^3)
// bitmask, backtracking, matrix exponentiation
class Solution_TLE {
public:
    int buildWall(int height, int width, vector<int>& bricks) {
        vector<int> patterns;
        unordered_set<int> lookup;
        backtracking(height, width, bricks, 0, 0, &lookup, &patterns);
        if (empty(patterns)) {
            return 0;
        }
        vector<vector<int>> matrix;
        vector<vector<int>> counts = {vector<int>(size(patterns), 1)};
        for (const auto& mask1 : patterns) {
            matrix.emplace_back();
            for (const auto& mask2 : patterns) {
                matrix.back().emplace_back(static_cast<int>((mask1 & mask2) == 0));
            }
        }
        const auto& result = matrixMult(counts, matrixExpo(matrix, height - 1));  // Time: O(p^3 * logh), Space: O(p^2)
        return accumulate(cbegin(result[0]), cend(result[0]), 0,
                          [](const auto& total, const auto& x) {
                              return (total + x) % MOD;
                          });  // Time: O(p)
    }

private:
    void backtracking(
        int height, int width, const vector<int>& bricks,
        int total, int mask,
        unordered_set<int> *lookup,
        vector<int> *patterns) {

        if (lookup->count(mask)) {
            return;
        }
        lookup->emplace(mask);
        if (total >= width) {
            if (total == width) {
                patterns->emplace_back(mask ^ (1 << width));
            }
            return;
        }
        for (const auto& x : bricks) {
            backtracking(height, width, bricks, total + x, mask | (1 << (total + x)), lookup, patterns);
        }

    }
    
    vector<vector<int>> matrixExpo(const vector<vector<int>>& A, int pow) {
        vector<vector<int>> result(A.size(), vector<int>(A.size()));
        vector<vector<int>> A_exp(A);
        for (int i = 0; i < A.size(); ++i) {
            result[i][i] = 1;
        }
        while (pow) {
            if (pow % 2 == 1) {
                result = matrixMult(result, A_exp);
            }
            A_exp = matrixMult(A_exp, A_exp);
            pow /= 2;
        }
        return result;
    }

    vector<vector<int>> matrixMult(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        vector<vector<int>> result(A.size(), vector<int>(B[0].size()));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B[0].size(); ++j) {
                int64_t entry = 0;
                for (int k = 0; k < B.size(); ++k) {
                    entry = (static_cast<int64_t>(A[i][k]) * B[k][j] % MOD + entry) % MOD;
                }
                result[i][j] = static_cast<int>(entry);
            }
        }
        return result;
    }

    static const int MOD = 1e9 + 7;
};
