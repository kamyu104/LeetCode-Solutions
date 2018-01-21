// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int result = 0;
        for (int i = 0, max_i = 0; i < arr.size(); ++i) {
            max_i = max(max_i, arr[i]);
            if (max_i == i) ++result;
        }
        return result;
    }
};
