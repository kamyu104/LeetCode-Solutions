// Time:  O(n * (C(2n, n) - C(2n, n - 1)))
// Space: O(n^2 * (C(2n, n) - C(2n, n - 1)))

class Solution {
  public:
    vector<int> diffWaysToCompute(string input) {
        vector<vector<vector<int>>> lookup(input.length() + 1,
                                           vector<vector<int>>(input.length() + 1, vector<int>()));
        return diffWaysToComputeRecu(input, 0, input.length(), lookup);
    }

    vector<int> diffWaysToComputeRecu(const string& input,
                                      const int start, const int end,
                                      vector<vector<vector<int>>>& lookup) {
        if (!lookup[start][end].empty()) {
            return lookup[start][end];
        }
        vector<int> result;
        for (int i = start; i < end; ++i) {
            const auto cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                vector<int> left = move(diffWaysToComputeRecu(input, start, i, lookup));
                vector<int> right = movediffWaysToComputeRecu(input, i + 1, end, lookup));
                for (const auto& num1 : left) {
                    for (const auto& num2 : right) {
                        if (cur == '+') {
                            result.emplace_back(num1 + num2);
                        } else if (cur == '-') {
                            result.emplace_back(num1 - num2);
                        } else {
                            result.emplace_back(num1 * num2);
                        }
                    }
                }
            }
        }
        // If the input string contains only number.
        if (result.empty()) {
            result.emplace_back(stoi(input.substr(start, end - start)));
        }
        lookup[start][end] = move(result);
        return lookup[start][end];
    }
};

// Time:  O(n^2 * (C(2n, n) - C(2n, n - 1)))
// Space: O(C(2n, n) - C(2n, n - 1))
class Solution2 {
  public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for (int i = 0; i < input.size(); ++i) {
            const auto cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                vector<int> left = move(diffWaysToCompute(input.substr(0, i)));
                vector<int> right = move(diffWaysToCompute(input.substr(i + 1)));
                for (const auto& num1 : left) {
                    for (const auto& num2 : right) {
                        if (cur == '+') {
                            result.emplace_back(num1 + num2);
                        } else if (cur == '-') {
                            result.emplace_back(num1 - num2);
                        } else {
                            result.emplace_back(num1 * num2);
                        }
                    }
                }
            }
        }
        // If the input string contains only number.
        if (result.empty()) {
            result.emplace_back(stoi(input));
        }
        return result;
    }
};
