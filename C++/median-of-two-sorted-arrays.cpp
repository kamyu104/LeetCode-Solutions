// Time:  O(log(min(m, n)))
// Space: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const auto& binary_search = [](int left, int right, const auto& check) {
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        const auto& findKthInTwoSortedArrays = [&](auto& A, auto& B, int k) {
            int m = size(A);
            int n = size(B);

            // Make sure m is the smaller one.
            if (m > n) {
                swap(m, n);
                swap(A, B);
            }

            // Find a partition of A and B
            // where min i s.t. A[i] >= B[k - 1 - i]. Thus A[i] is the (k+1)-th or above element.
            const int i = binary_search(max(k - n, 0), min(m, k) - 1, [&](int i) {
                return A[i] >= B[k - 1 - i];
            });
            // kth element would be A[i - 1] or B[k - 1 - i].
            const int Ai_minus_1 = i - 1 >= 0 ? A[i - 1] : numeric_limits<int>::min();
            const int Bj = k - 1 - i >= 0 ? B[k - 1 - i] : numeric_limits<int>::min();
            return max(Ai_minus_1, Bj);
        };

        if ((size(nums1) + size(nums2)) % 2 == 1) {
            return findKthInTwoSortedArrays(nums1, nums2, (size(nums1) + size(nums2)) / 2 + 1);
        } else {
            return (findKthInTwoSortedArrays(nums1, nums2, (size(nums1) + size(nums2)) / 2) +
                    findKthInTwoSortedArrays(nums1, nums2, (size(nums1) + size(nums2)) / 2 + 1)) / 2.0;
        }
    }
};

// Time:  O(log(max(m, n)) * log(max_val - min_val))
// Space: O(1)
// Generic solution.
class Solution_Generic {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const auto& binary_search = [](int left, int right, const auto& check) {
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        const auto& findKthInSortedArrays = [&](const auto& arrays, int k) {
            const auto& check = [&](int num) {
                int res = 0;
                for (const auto& arr : arrays) {
                    if (!empty(*arr)) {  // count the number of values which are less or equal to num
                        res += distance(cbegin(*arr), upper_bound(cbegin(*arr), cend(*arr), num));
                    }
                }
                return res >= k;
            };

            int left = numeric_limits<int>::max();
            int right = numeric_limits<int>::min();
            for (const auto arr : arrays) {
                if (!empty(*arr)) {
                    left = min(left, arr->front());
                    right = max(right, arr->back());
                }
            }
            return binary_search(left, right, check);
        };

        vector<vector<int> *> arrays{&nums1, &nums2};
        int total = accumulate(cbegin(arrays), cend(arrays), 0, [](const auto& x, const auto& y) {
            return x + size(*y);
        });
        if (total % 2 == 1) {
            return findKthInSortedArrays(arrays, total / 2 + 1);
        } else {
            return (findKthInSortedArrays(arrays, total / 2) +
                    findKthInSortedArrays(arrays, total / 2 + 1)) / 2.0;
        }
    }
};
