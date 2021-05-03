// Time:  O((k + n) * n)
// Space: O(n)

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string new_num = num;
        while (k--) {
            next_permutation(begin(new_num), end(new_num));
        }
        int result = 0;
        for (int i = 0; i < size(new_num); ++i) {
            if (new_num[i] == num[i]) {
                continue;
            }
            int j = i + 1;  // greedily swap the one with the least cost from new_num to num without missing optimal cost
            for (; j < size(new_num) && new_num[j] != num[i]; ++j);
            result += j - i;
            for (; j > i; --j) {
                swap(new_num[j - 1], new_num[j]);
            }
        }
        return result;
    }
};
