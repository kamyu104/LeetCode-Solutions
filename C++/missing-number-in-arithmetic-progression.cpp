// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        const auto& d = (arr.back() - arr[0]) / static_cast<int>(arr.size());
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(arr, d, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return arr[0] + d * left;
    }
    
private:
    bool check(const vector<int>& arr, int d, int x) {
        return arr[x] != arr[0] + d * x;
    }
};

// Time:  O(logn)
// Space: O(1)
class Solution2 {
public:
    int missingNumber(vector<int>& arr) {
        return (*min_element(arr.cbegin(), arr.cend()) +
                *max_element(arr.cbegin(), arr.cend())) *
               (arr.size() + 1) / 2 -
               accumulate(arr.cbegin(), arr.cend(), 0);
    }
};
