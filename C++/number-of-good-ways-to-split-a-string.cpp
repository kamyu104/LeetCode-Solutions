// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numSplits(string s) {
        vector<int> left(26), right(26);
        int right_count = 0;
        for (const auto& c : s) {
            right_count += int(++right[c - 'a'] == 1);
        }
        int result = 0, left_count = 0;
        for (const auto& c : s) {
            left_count += int(++left[c - 'a'] == 1);
            right_count -= int(--right[c - 'a'] == 0);
            result += int(left_count == right_count);
        }
        return result;
    }
};
