// Time:  O(k * (n/k)log(n/k)) = O(nlog(n/k))
// Space: O(n/k)

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int result = size(arr);
        for (int i = 0; i < k; ++i) {
            vector<int> longest_non_decreasing_subsequence;
            for (int j = i; j < size(arr); j += k) {
                auto it = upper_bound(begin(longest_non_decreasing_subsequence), end(longest_non_decreasing_subsequence), arr[j]);
                if (it == end(longest_non_decreasing_subsequence)) {
                    longest_non_decreasing_subsequence.emplace_back(arr[j]);
                } else {
                    *it = arr[j];
                }
            }
            result -= size(longest_non_decreasing_subsequence);
        }
        return result;
    }
};
