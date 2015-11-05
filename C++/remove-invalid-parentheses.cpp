// Time:  O(C(n, c)), try out all possible substrings with the minimum c deletion.
// Space: O(c), the depth is at most c, and it costs n at each depth

// DFS solution with removed array. (4ms)
class Solution {
public:
    vector<string> removeInvalidParentheses(string s)  {
        int left_removed = 0, right_removed = 0;
        findMinRemove(s, &left_removed, &right_removed);

        vector<string> res;
        vector<int> removed;
        removeInvalidParenthesesHelper(s, 0, left_removed, right_removed, &removed, &res);
        return res;
    }

private:
    void findMinRemove(const string& s, int *left_removed, int *right_removed) {
        // Calculate the minimum left and right parantheses to remove.
        for (const auto& c : s) {
            if (c == '(') {
                ++(*left_removed);
            } else if (c == ')') {
                if (!(*left_removed)) {
                    ++(*right_removed);
                } else {
                    --(*left_removed);
                }
            }
        }
    }

    void removeInvalidParenthesesHelper(const string& s, int start,
                                  int left_removed, int right_removed,
                                  vector<int> *removed, vector<string> *res) {

        if (left_removed == 0 && right_removed == 0) { 
            string tmp;
            for (int i = 0, j = 0; i < s.length(); ++i) {
                if (j < removed->size() && i == (*removed)[j]) {
                    ++j;
                } else {
                    tmp.push_back(s[i]);
                }
            }
            if (isValid(tmp)) {
                res->emplace_back(tmp);
            }
            return;
        }

        for (int i = start; i < s.length(); ++i) {
            if (right_removed == 0 && left_removed > 0 && s[i] == '(') {
                if (i == start || s[i] != s[i - 1]) {  // Skip duplicated.
                    removed->emplace_back(i);
                    removeInvalidParenthesesHelper(s, i + 1, left_removed - 1, right_removed,
                                                   removed, res);
                    removed->pop_back();
                }
            } else if (right_removed > 0 && s[i] == ')') {
                if (i == start || s[i] != s[i - 1]) {  // Skip duplicated.
                    removed->emplace_back(i);
                    removeInvalidParenthesesHelper(s, i + 1, left_removed, right_removed - 1,
                                                   removed, res);
                    removed->pop_back();
                }
            }

        }
    }

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

// Time:  O(C(n, c)), try out all possible substrings with the minimum c deletion.
// Space: O(c), the depth is at most c, and it costs n at each depth
// DFS solution with removed hash. (8ms)
class Solution2 {
public:
    vector<string> removeInvalidParentheses(string s)  {
        int left_removed = 0, right_removed = 0;
        findMinRemove(s, &left_removed, &right_removed);

        vector<string> res;
        unordered_set<int> removed;
        removeInvalidParenthesesHelper(s, 0, left_removed, right_removed, &removed, &res);
        return res;
    }

private:
    void findMinRemove(const string& s, int *left_removed, int *right_removed) {
        // Calculate the minimum left and right parantheses to remove.
        for (const auto& c : s) {
            if (c == '(') {
                ++(*left_removed);
            } else if (c == ')') {
                if (!(*left_removed)) {
                    ++(*right_removed);
                } else {
                    --(*left_removed);
                }
            }
        }
    }

    void removeInvalidParenthesesHelper(const string& s, int start,
                                  int left_removed, int right_removed,
                                  unordered_set<int> *removed, vector<string> *res) {

        if (left_removed == 0 && right_removed == 0) { 
            string tmp;
            for (int i = 0; i < s.length(); ++i) {
                if (!removed->count(i)) {
                    tmp.push_back(s[i]);
                }
            }
            if (isValid(tmp)) {
                res->emplace_back(tmp);
            }
            return;
        }

        for (int i = start; i < s.length(); ++i) {
            if (right_removed == 0 && left_removed > 0 && s[i] == '(') {
                if (i == start || s[i] != s[i - 1]) {  // Skip duplicated.
                    removed->emplace(i);
                    removeInvalidParenthesesHelper(s, i + 1, left_removed - 1, right_removed,
                                                   removed, res);
                    removed->erase(i);
                }
            } else if (right_removed > 0 && s[i] == ')') {
                if (i == start || s[i] != s[i - 1]) {  // Skip duplicated.
                    removed->emplace(i);
                    removeInvalidParenthesesHelper(s, i + 1, left_removed, right_removed - 1,
                                                   removed, res);
                    removed->erase(i);
                }
            }

        }
    }

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


// Time:  O(n * C(n, c)), try out all possible substrings with the minimum c deletion.
// Space: O(n * c), the depth is at most c, and it costs n at each depth
// DFS solution. (4ms)
class Solution3 {
public:
    vector<string> removeInvalidParentheses(string s)  {
        int left_removed = 0, right_removed = 0;
        findMinRemove(s, &left_removed, &right_removed);

        vector<string> res;
        removeInvalidParenthesesHelper(s, 0, left_removed, right_removed, &res);
        return res;
    }

    void findMinRemove(const string& s, int *left_removed, int *right_removed) {
        // Calculate the minimum left and right parantheses to remove.
        for (const auto& c : s) {
            if (c == '(') {
                ++(*left_removed);
            } else if (c == ')') {
                if (!(*left_removed)) {
                    ++(*right_removed);
                } else {
                    --(*left_removed);
                }
            }
        }
    }

private:
    void removeInvalidParenthesesHelper(const string& s, int start,
                                  int left_removed, int right_removed, vector<string> *res) {

        if (left_removed == 0 && right_removed == 0) {   
            if (isValid(s)) {
                res->emplace_back(s);
            }
            return;
        }

        for (int i = start; i < s.length(); ++i) {
            if (right_removed == 0 && left_removed > 0 && s[i] == '(') {
                if (i == start || s[i] != s[i - 1]) {  // Skip duplicated.
                    string tmp = s;
                    tmp.erase(i, 1);
                    removeInvalidParenthesesHelper(tmp, i, left_removed - 1, right_removed, res);
                }
            } else if (right_removed > 0 && s[i] == ')') {
                if (i == start || s[i] != s[i - 1]) {  // Skip duplicated.
                    string tmp = s;
                    tmp.erase(i, 1);
                    removeInvalidParenthesesHelper(tmp, i, left_removed, right_removed - 1, res);
                }
            }

        }
    }

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
