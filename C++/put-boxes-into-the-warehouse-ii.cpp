// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(rbegin(boxes), rend(boxes));
        int left = 0, right = size(warehouse) - 1;
        for (const auto& h : boxes) {
            if (h <= warehouse[left]) {
                ++left;
            } else if (h <= warehouse[right]) {
                --right;
            }
            if (left > right) {
                break;
            }
        }
        return left + (size(warehouse) - 1 - right);
    }
};
