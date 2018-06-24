// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int scoreOfParentheses(string S) {
        int result = 0, depth = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '(') {
                ++depth;
            } else {
                --depth;
                if (S[i - 1] == '(') {
                    result += 1 << depth;
                }
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    int scoreOfParentheses(string S) {
        vector<int> stack(1, 0);
        for (const auto& c : S) {
            if (c == '(') {
                stack.emplace_back(0);
            } else {
                const auto last = stack.back(); stack.pop_back();
                stack.back() += max(1, 2 * last);
            }
        }
        return stack.front();
    }
};
