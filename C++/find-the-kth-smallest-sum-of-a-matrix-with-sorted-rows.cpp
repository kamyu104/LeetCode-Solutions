// Time:  O(m * klogk)
// Space: O(k)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        auto result = mat[0];
        for (int r = 1; r < mat.size(); ++r) {
            result = kSmallestPairs(result, mat[r], k);
        }
        return result[k - 1];
    }

private:
    vector<int> kSmallestPairs(const vector<int>& nums1, const vector<int>&  nums2, int k) {
        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (int c = 0; c < min(int(nums1.size()), k); ++c) {
            min_heap.emplace(nums1[c] + nums2[0], 0);
        }
        while (result.size() != k && !min_heap.empty()) {
            const auto [total, c] = min_heap.top(); min_heap.pop();
            result.emplace_back(total);
            if (c + 1 == nums2.size()) {
                continue;
            }
            min_heap.emplace(total - nums2[c] + nums2[c + 1], c + 1);
        }
        return result;
    }
};
