// Time:  O(n)
// Space: O(1)

// the followings are invariant if the number of 'X' in both strings are the same
// 1. the ordering of 'L', 'R' in both strings are the same
// 2. for each position (i, j) of paired 'L' character in both strings, i >= j
// 3. for each position (i, j) of paired 'R' character in both strings, i <= j
class Solution {
public:
    bool canTransform(string start, string end) {
        int count = 0;
        for (int i = 0; i < size(start); ++i) {
            if (start[i] == 'X') {
                ++count;
            }
            if (end[i] == 'X') {
                --count;
            }
        }
        if (count) {
            return false;
        }
        for (int i = 0, j = 0; i < size(start) && j < size(end); ++i, ++j) {
            while (i < size(start) && start[i] == 'X') {
                ++i;
            }
            while (j < size(end) && end[j] == 'X') {
                ++j;
            }
            if ((i < size(start)) != (j < size(end))) {
                return false;
            }
            if (i < size(start) && j < size(end)) {
                if (start[i] != end[j] ||
                    (start[i] == 'L' && i < j) ||
                    (start[i] == 'R' && i > j)) {
                    return false;
                }
            }
        }
        return true;
    }
};
