// Time:  O(n)
// space: O(1)

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, numeric_limits<int>::max());
        vector<int> last(26, numeric_limits<int>::min());
        for (int i = 0; i < s.length(); ++i) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = max(last[s[i] - 'a'], i);
        }
        vector<string> result(1);
        int right = numeric_limits<int>::max();
        for (int left = 0; left < s.length(); ++left) {
            if (left != first[s[left] - 'a']) {
                continue;
            }
            int new_right = findRightFromLeft(s, first, last, left);
            if (new_right == -1) {
                continue;
            }
            if (left > right) {
                result.emplace_back();     
            }
            right = new_right;
            result.back() = s.substr(left, right - left + 1);
        }
        return result;
    }

private:
    int findRightFromLeft(const string &s,
                          const vector<int>& first,
                          const vector<int>& last,
                          int left) {
        int right = last[s[left] - 'a'];
        for (auto i = left; i <= right; ++i) {
            if (first[s[i] - 'a'] < left) {
                return -1;
            }
            right = max(right, last[s[i] - 'a']);
        }
        return right;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, numeric_limits<int>::max());
        vector<int> last(26, numeric_limits<int>::min());
        for (int i = 0; i < s.length(); ++i) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = max(last[s[i] - 'a'], i);
        }
        vector<pair<int, int>> intervals;
        for (int c = 0; c < first.size(); ++c) {
            if (first[c] == numeric_limits<int>::max()) {
                continue;
            }
            int left = first[c], right = findRightFromLeft(s, first, last, first[c]);
            if (right != -1) {
                intervals.emplace_back(right, left);
            }
        }
        sort(begin(intervals), end(intervals));  // Time: O(26log26)
        vector<string> result;
        int prev = -1;
        for (const auto& [right, left] : intervals) {
            if (left <= prev) {
                continue;
            }
            result.emplace_back(s.substr(left, right - left + 1));
            prev = right;
        }
        return result;
    }

private:
    int findRightFromLeft(const string &s,
                          const vector<int>& first,
                          const vector<int>& last,
                          int left) {
        int right = last[s[left] - 'a'];
        for (auto i = left; i <= right; ++i) {
            if (first[s[i] - 'a'] < left) {
                return -1;
            }
            right = max(right, last[s[i] - 'a']);
        }
        return right;
    }
};
