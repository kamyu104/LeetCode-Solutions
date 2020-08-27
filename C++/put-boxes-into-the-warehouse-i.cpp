// Time:  O(nlogn + m)
// Space: O(1)

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(rbegin(boxes), rend(boxes));
        int result = 0;
        for (const auto& h : boxes) {
            if (h > warehouse[result]) {
                continue;
            }
            if (++result == warehouse.size()) {
                break;
            }
        }
        return result;
    }
};

// Time:  O(nlogn + m)
// Space: O(1)
class Solution2 {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(begin(boxes), end(boxes));
        for (int i = 1; i < warehouse.size(); ++i) {
            warehouse[i] = min(warehouse[i], warehouse[i - 1]);
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
