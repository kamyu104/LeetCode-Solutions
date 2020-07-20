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
