// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int result = 1;
        for (int i = 1; i < size(arr); ++i) {
            result = min(result + 1, arr[i]);
        }
        return result;
    }
};
