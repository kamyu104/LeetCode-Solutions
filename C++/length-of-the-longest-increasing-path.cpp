// Time:  O(nlogn)
// Space: O(n)

// sort, binary search, longest increasing subsequence, lis
class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        const auto& longest_increasing_subsequence = [](const auto& arr) {
            vector<int> result;
            for (const auto& x : arr) {
                auto it = lower_bound(begin(result), end(result), x);
                if (it == end(result)) {
                    result.emplace_back(x);
                } else {
                    *it = x;
                }
            }
            return size(result);
        };

        const auto target = coordinates[k];
        sort(begin(coordinates), end(coordinates), [](const auto& a, const auto& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });
        vector<int> left, right;
        for (const auto& x : coordinates) {
            if (x[0] < target[0] && x[1] < target[1]) {
                left.emplace_back(x[1]);
            } else if (x[0] > target[0] && x[1] > target[1]) {
                right.emplace_back(x[1]);
            }
        }
        return longest_increasing_subsequence(left) + 1 + longest_increasing_subsequence(right);
    }
};
