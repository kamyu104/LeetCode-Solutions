// Time:  O((m + n) * logr), r is the range size of [min(products), max(products)]
// Space: O(1)

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        const auto& neg_cnt = accumulate(cbegin(nums1), cend(nums1), 0ull,
                              [](const auto& total, const auto& x) {
                                  return total + (x < 0);
                              });
        int64_t left = numeric_limits<int64_t>::max();
        int64_t right = numeric_limits<int64_t>::min();
        for (const auto& i : {0ul, size(nums1) - 1}) {
            for (const auto& j : {0ul, size(nums2) - 1}) {
                left = min(left, static_cast<int64_t>(nums1[i]) * nums2[j]);
                right = max(right, static_cast<int64_t>(nums1[i]) * nums2[j]);
            }
        }
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (check(nums1, nums2, k, neg_cnt, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool check(const vector<int>& nums1, const vector<int>& nums2,
               int64_t k, int neg_cnt, int64_t target) {
        int start = target >= 0 ? neg_cnt - 1 : 0;
        int end = target >= 0 ? -1 : neg_cnt;
        int d = target >= 0 ? -1 : 1;
        int64_t cnt = 0;
        int left = 0, right = size(nums2) - 1;
        for (int i = start; i != end; i += d) {
            while (left < size(nums2) && static_cast<int64_t>(nums1[i]) * nums2[left] > target) {
                ++left;
            }
            cnt += (size(nums2) - 1) - left + 1;
        }        
        start = target >= 0 ? neg_cnt : size(nums1) - 1;
        end = target >= 0 ? size(nums1) : neg_cnt - 1;
        d = target >= 0 ? 1 : -1;
        for (int i = start; i != end; i += d) {
            if (nums1[i] == 0) {
                if (target >= 0) {
                    cnt += size(nums2);
                }
                continue;
            }
            while (right >= 0 && static_cast<int64_t>(nums1[i]) * nums2[right] > target) {
                --right;
            }
            cnt += right - 0 + 1;
        }
        return cnt >= k;
    }
};
