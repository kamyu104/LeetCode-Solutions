// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = size(arr) - 1;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
