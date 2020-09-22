// Time:  O(log(min(m, n)))
// Space: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            return findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1);
        } else {
            return (findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2) +
                    findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1)) / 2.0;
        }
    }

    int findKthInTwoSortedArrays(const vector<int>& A, const vector<int>& B,
                                 int k) {
        const int m = A.size();
        const int n = B.size();

        // Make sure m is the smaller one.
        if (m > n) {
            return findKthInTwoSortedArrays(B, A, k);
        }

        int left = 0;
        int right = m;
        // Find a partition of A and B
        // where min left s.t. A[left] >= B[k - 1 - left]. Thus A[left] is the (k+1)-th or above element.
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (0 <= k - 1 - mid && k - 1 - mid < n && A[mid] >= B[k - 1 - mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int Ai_minus_1 = left - 1 >= 0 ? A[left - 1] : numeric_limits<int>::min();
        int Bj = k - 1 - left >= 0 ? B[k - 1 - left] : numeric_limits<int>::min();

        // kth element would be A[left - 1] or B[k - 1 - left].
        return max(Ai_minus_1, Bj);
    }
};

// Time:  O(log(max(m, n)) * log(max_val - min_val))
// Space: O(1)
// Generic solution.
class Solution_Generic {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int> *> arrays{&nums1, &nums2};
        int total = accumulate(cbegin(arrays), cend(arrays), 0,
                               [](const auto& x, const auto& y) {
                                   return x + size(*y);
                               });
        if (total % 2 == 1) {
            return findKthInSortedArrays(arrays, total / 2 + 1);
        } else {
            return (findKthInSortedArrays(arrays, total / 2) +
                    findKthInSortedArrays(arrays, total / 2 + 1)) / 2.0;
        }
    }

private:
    int findKthInSortedArrays(const vector<vector<int> *>& arrays, int k) {
        int left = numeric_limits<int>::max();
        int right = numeric_limits<int>::min();
        for (const auto array : arrays) {
            if (!empty(*array)) {
                left = min(left, array->front());
                right = max(right, array->back());
            }
        }
        // left xxxxxxxooooooo right, find first xo or oo
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (check(arrays, mid, k)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool check(const vector<vector<int> *>& arrays, int num, int target) {
        int res = 0;
        for (const auto array : arrays) {
            if (!array->empty()) {  // count the number of values which are less or equal to num
                res += distance(array->cbegin(),
                                upper_bound(array->cbegin(), array->cend(), num));
            }
        }
        return res >= target;
    }
};
