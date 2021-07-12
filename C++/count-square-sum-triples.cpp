// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int countTriples(int n) {
        unordered_set<int> lookup;
        for (int i = 1; i <= n; ++i) {
            lookup.emplace(i * i);
        }
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                result += lookup.count(i * i + j * j);
            }
        }
        return result;
    }
};
