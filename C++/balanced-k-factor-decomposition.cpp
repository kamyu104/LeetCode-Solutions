// Time:  O(k * sqrt(n)^(k - 1))
// Space: O(k)

// backtracking, number theory
class Solution {
public:
    vector<int> minDifference(int n, int k) {
        vector<int> result, curr;
        function<void (int, int)> backtracking = [&](int remain, int start) {
            if (size(curr) == k - 1) {
                if (remain >= start) {
                    curr.emplace_back(remain);
                    if (empty(result) || result.back() - result[0] > curr.back() - curr[0]) {
                        result = curr;
                    }
                    curr.pop_back();
                }
                return;
            }
            for (int i = 1; i * i <= remain; ++i) {
                if (remain % i) {
                    continue;
                }
                const int j = remain / i;
                if (i >= start) {
                    curr.emplace_back(i);
                    backtracking(j, i);
                    curr.pop_back();
                }
                if (j == i) {
                    continue;
                }
                if (j >= start) {
                    curr.emplace_back(j);
                    backtracking(i, j);
                    curr.pop_back();
                }
            }
        };

        backtracking(n, 1);
        return result;
    }
};
