// Time:  O(C(2n, n) - C(2n, n - 1))
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
        if (start == end) {
            return {};
        }
        
        if (!lookup[start][end].empty()) {
            return lookup[start][end];
        }

        vector<int> result;
        int i = start;
        while (i < end && !isOperator(input[i])) {
            ++i;
        }
        if (i == end) {
            result.emplace_back(move(stoi(input.substr(start, end - start))));
            return result;
        }

        i = start;
        while (i < end) {
            while (i < end && !isOperator(input[i])) {
                ++i;
            }
            if (i < end) {
                vector<int> left = diffWaysToComputeRecu(input, start, i, lookup);
                vector<int> right = diffWaysToComputeRecu(input, i + 1, end, lookup);
                for (int j = 0; j < left.size(); ++j) {
                    for(int k = 0; k < right.size(); ++k) {
                        result.emplace_back(move(compute(input[i],left[j], right[k])));
                    }
                }
            }
            ++i;
        }
        lookup[start][end] = move(result);
        return lookup[start][end];
    }

    bool isOperator(const char c){
        return string("+-*").find(string(1, c)) != string::npos;
    }

    int compute(const char c, const int left, const int right){
        switch (c) {
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '*':
                return left * right;
            default:
                return 0;
        }
        return 0;
    }
};

// Time:  O(n^2 * (C(2n, n) - C(2n, n - 1)))
// Space: O(C(2n, n) - C(2n, n - 1))
class Solution2 {
  public:
    vector<int> diffWaysToCompute(string input) {
        return diffWaysToComputeRecu(input, 0, input.length());
    }

    vector<int> diffWaysToComputeRecu(const string& input,
                                      const int start, const int end) {
        if (start == end) {
            return {};
        }

        vector<int> result;
        int i = start;
        while (i < end && !isOperator(input[i])) {
            ++i;
        }
        if (i == end) {
            result.emplace_back(move(stoi(input.substr(start, end - start))));
            return result;
        }

        i = start;
        while (i < end) {
            while (i < end && !isOperator(input[i])) {
                ++i;
            }
            if (i < end) {
                vector<int> left = diffWaysToComputeRecu(input, start, i);
                vector<int> right = diffWaysToComputeRecu(input, i + 1, end);
                for (int j = 0; j < left.size(); ++j) {
                    for(int k = 0; k < right.size(); ++k) {
                        result.emplace_back(move(compute(input[i],left[j], right[k])));
                    }
                }
            }
            ++i;
        }
        return result;
    }

    bool isOperator(const char c){
        return string("+-*").find(string(1, c)) != string::npos;
    }

    int compute(const char c, const int left, const int right){
        switch (c) {
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '*':
                return left * right;
            default:
                return 0;
        }
        return 0;
    }
};
