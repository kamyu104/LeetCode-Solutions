// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int result = 0;
        for (int i = 0; i <= size(target); ++i) {
            result += max((i < size(target) ? target[i] : 0) - (i - 1 >= 0 ? target[i - 1] : 0), 0);
        }
        return result;
    }
};
