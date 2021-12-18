// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int result = 0 ;
        int left = 0, right = size(plants) - 1;
        int canA = capacityA, canB = capacityB;
        while (left < right) {
            if (canA < plants[left]) {
                 ++result;
                canA = capacityA;
            }
            canA -= plants[left++];
            if (canB < plants[right]) {
                 ++result;
                canB = capacityB;
            }
            canB -= plants[right--];
        }
        if (left == right) {
            if (max(canA, canB) < plants[left]) {
                ++result;
            }
        }
        return result;
    }
};
