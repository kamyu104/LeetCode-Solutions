// Time:  O(logn)
// Space: O(1)

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = 19999;
        while (left <= right) {
            auto mid = left + (right-left) / 2;
            auto response = reader.get(mid);
            if (response > target) {
                right = mid - 1;
            } else if (response < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
