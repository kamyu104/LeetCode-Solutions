// Time:  O(logn)
// Space: O(1)

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = binarySearch(mountainArr, 0, mountainArr.length()-1,
                                [&](int x) { return mountainArr.get(x) >= mountainArr.get(x + 1); });
        int left = binarySearch(mountainArr, 0, peak,
                             [&](int x) { return mountainArr.get(x) >= target; });
        if (left <= peak && mountainArr.get(left) == target) {
            return left;
        }
        int right = binarySearch(mountainArr, peak, mountainArr.length() - 1,
                                 [&](int x) { return mountainArr.get(x) <= target; });
        if (right <= mountainArr.length() - 1 && mountainArr.get(right) == target) {
            return right;
        }
        return -1;
    }
    
private:
    int binarySearch(MountainArray &A, int left, int right,
                     const function<bool(int)>& check) {
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
