// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    bool canChange(string start, string target) {
        for (int i = 0, j = 0; true; ++i, ++j) {
            for (; i < size(start) && start[i] == '_'; ++i);
            for (; j < size(target) && target[j] == '_'; ++j);
            if (i == size(start) && j == size(target)) {
                break;
            }
            if (i == size(start) || j == size(target) || start[i] != target[j] ||
                (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) {
                    return false;
            }
        }
        return true;
    }
};
