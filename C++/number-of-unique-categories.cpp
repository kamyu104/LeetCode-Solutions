// Time:  O(n^2)
// Space: O(1)

// brute force
class Solution {
public:
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (categoryHandler->haveSameCategory(j, i)) {
                    ++cnt;
                    break;
                }
            }
        }
        return n - cnt;
    }
};
