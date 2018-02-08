// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool canTransform(string start, string end) {
        int N = start.length();
        for (int i = 0, j = 0; i < N && j < N; ++i, ++j) {
            while (i < N && start[i] == 'X') ++i;
            while (j < N && end[j] == 'X') ++j;
            if ((i < N) != (j < N)) {
                return false;
            } else if (i < N && j < N) {
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
