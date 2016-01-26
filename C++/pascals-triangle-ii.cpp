// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        for (int i = 0; i < result.size(); ++i) {
            int prev_result = result[0] = 1;
            for (int j = 1; j <= i; ++j) {
                int tmp = result[j];
                result[j] += prev_result;
                prev_result = tmp;
            }
        }
        return result;
    }
};
