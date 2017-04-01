// Time:  O(n^3) ~ O(n^4)
// Space: O(n^3)

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int lookup[100][100][100] = {0};
        return removeBoxesHelper(boxes, 0, boxes.size() - 1, 0, lookup);
    }
    
private:
    int removeBoxesHelper(const vector<int>& boxes, int l, int r, int k, int lookup[100][100][100]) {
        if (l > r) {
            return 0;
        }
        if (lookup[l][r][k]) {
            return lookup[l][r][k];
        }

        auto& result = lookup[l][r][k];
        while (l < r && boxes[l + 1] == boxes[l]) {
            ++l, ++k;
        }
        result = removeBoxesHelper(boxes, l + 1, r, 0, lookup) + (k + 1) * (k + 1);
        for (int i = l + 1; i <= r; ++i) {
            if (boxes[i] == boxes[l]) {
                result = max(result,
                             removeBoxesHelper(boxes, l + 1,  i - 1, 0, lookup) +
                             removeBoxesHelper(boxes, i, r, k + 1, lookup));
            }
        }
        return result;
    }
};
