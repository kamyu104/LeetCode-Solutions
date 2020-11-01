// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    int countSubstrings(string s, string t) {
        int result = 0;
        // for each possible alignment, count the number of substrs that differ by 1 char
        for (int i = 0; i < size(s); ++i) {
            result += count(s, t, i, 0);
        }
        for (int j = 1; j < size(t); ++j) {  // j starts from 1 to avoid duplicated count(0, 0)
            result += count(s, t, 0, j);
        }
        return result;
    }

private:
    int count(const string& s, const string& t, int i, int j) {
        int l = min(size(s) - i, size(t) - j);
        int result = 0, left_cnt = 0, right_cnt = 0;  // left and right consecutive same counts relative to the different char
        for (int k = 0; k < l; ++k) {
            ++right_cnt;
            if (s[i + k] != t[j + k]) {
                left_cnt = right_cnt;
                right_cnt = 0;
                // left_i = i+k-left+1
            }
            result += left_cnt;  // target substrs are [s[left_i+c:i+k+1] for c in xrange(left_cnt)]
        }
        return result;
    }
};
