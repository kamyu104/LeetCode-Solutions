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

// Time:  O((k + m) * log(m * MAX_NUM)) ~ O(k * m * log(m * MAX_NUM))
// Space: O(m)
class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int max_num = 0;
        for (const auto& row : mat) {
            max_num = max(max_num, *max_element(cbegin(row), cend(row)));
        }
        int left = mat.size(), right = mat.size() * max_num;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            const auto& cnt = countArraysHaveSumLessOrEqual(mat, k, 0, mid);
            if (cnt >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    int countArraysHaveSumLessOrEqual(const vector<vector<int>>& mat, int k, int r, int target) {  // Time: O(k + m) ~ O(k * m)
        if (target < 0)  {
            return 0;
        }
        if (r == mat.size()) {
            return 1;
        }
        int result = 0;
        for (int c = 0; c < mat[0].size(); ++c) {
            int cnt = countArraysHaveSumLessOrEqual(mat, k - result, r + 1, target - mat[r][c]);
            if (!cnt) {
                break;
            }
            result += cnt;
            if (result > k) {
                break;
            }
        }
        return result;
    }
};
