// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (!check(arr, k, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right + 1 + k;  // right >= 0 ? arr[right] + (k - (arr[right] - (right + 1))) : k;
    }

private:
    bool check(const vector<int>& arr, int k, int x) {
        return arr[x] - (x + 1) < k;
    }
};
