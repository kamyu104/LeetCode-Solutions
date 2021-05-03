// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    bool splitString(string s) {
        return backtracking(s, 0, -1, 0);
    }

private:
    bool backtracking(const string& s, int i, int64_t num, int cnt) {
        if (i == size(s)) {
            return cnt >= 2;
        }
        int64_t new_num = 0;
        for (int j = i; j < size(s); ++j) {
            new_num = new_num * 10 + (s[j] - '0');
            if (new_num >= 1e10) {
                break;
            }
            if (new_num >= num && num >= 0) {
                break;
            }
            if ((num == -1 || (num - 1) == new_num) && backtracking(s, j + 1, new_num, cnt + 1)) {
                return true;
            }
        }
        return false;
    }
};
