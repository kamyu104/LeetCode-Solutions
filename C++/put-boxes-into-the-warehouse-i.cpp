// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(begin(boxes), end(boxes));
        int min_h = warehouse[0];
        for (auto& h : warehouse) {
            h = min_h = min(min_h, h);
        }
        int result = 0, curr = 0;
        for (int i = warehouse.size() - 1; i >= 0; --i) {
            if (boxes[curr] > warehouse[i]) {
                continue;
            }
            ++result;
            if (++curr == boxes.size()) {
                break;
            }
        }
        return result;
    }
};
