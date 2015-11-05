// DFS solution.
class Solution {
public:
    vector<string> removeInvalidParentheses(string s)  {
        // Calculate the minimum left and right parantheses to remove
        int left_removed = 0, right_removed = 0;
        for (const auto& c : s) {
            if (c == '(') {
                ++left_removed;
            } else if (c == ')') {
                if (!left_removed) {
                    ++right_removed;
                } else {
                    --left_removed;
                }
            }
        }
        vector<string> res;
        removeInvalidParentheses(s, 0, left_removed, right_removed, &res);
        return res;
    }


    void removeInvalidParentheses(const string& s, int start,
                                  int left_removed, int right_removed, vector<string> *res) {

        if (left_removed == 0 && right_removed == 0) {   
            if (isValid(s)) {
                res->emplace_back(s);
            }
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            string tmp = s;
            if (right_removed == 0 && left_removed > 0 && tmp[i] == '(') {
                if (i == start || tmp[i] != tmp[i - 1]) {  // Skip duplicated.
                    tmp.erase(i, 1);
                    removeInvalidParentheses(tmp, i, left_removed - 1, right_removed, res);
                }
            }
            if (right_removed > 0 && tmp[i] == ')') {
                if (i == start || tmp[i] != tmp[i - 1]) {  // Skip duplicated.
                    tmp.erase(i, 1);
                    removeInvalidParentheses(tmp, i, left_removed, right_removed - 1, res);
                }
            }

        }
    }

private:
    // Check whether s is valid or not.
    bool isValid(string s) {
        int sum = 0;
        for (const auto &c : s) {
            if (c == '(') {
                ++sum;
            } else if (c == ')') {
                --sum;
            }
            if (sum < 0) {
                return false;
            }
        }
        return sum == 0;
    }
};
