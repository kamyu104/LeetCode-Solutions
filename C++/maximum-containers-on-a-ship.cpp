// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        return min(maxWeight / w, n * n);
    }
};
