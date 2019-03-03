// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool isValid(string S) {
        string stack;
        for (const auto& c : S) {
            if (c == 'c') {
                if (stack.size() >= 2 &&
                    stack[stack.length() - 2] == 'a' &&
                    stack[stack.length() - 1] == 'b') {

                    stack.pop_back();
                    stack.pop_back();
                } else {
                    return false;
                }
            } else {
                stack.push_back(c);
            }
        }
        return stack.empty();
    }
};
