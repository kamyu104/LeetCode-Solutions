// Time:  O(n)
// Space: O(1)

// simulation
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < size(nums1); ++i) {
            if (!(min(nums1[i], nums2[i]) <= min(nums1.back(), nums2.back()) &&
                  max(nums1[i], nums2[i]) <= max(nums1.back(), nums2.back()))) {
                return -1;
            }
            if (!(nums1[i] <= nums1.back() && nums2[i] <= nums2.back())) {
                ++cnt1;
            }
            if (!(nums1[i] <= nums2.back() && nums2[i] <= nums1.back())) {
                ++cnt2;
            }
        }
        return min(cnt1, cnt2);
    }
};

// Time:  O(n)
// Space: O(1)
// simulation
class Solution2 {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        static const int INF = numeric_limits<int>::max();

        const auto& count = [&](int mx1, int mx2) {
            int result = 0;
            for (int i = 0; i < size(nums1); ++i) {
                if (nums1[i] <= mx1 && nums2[i] <= mx2) {
                    continue;
                }
                if (!(nums2[i] <= mx1 && nums1[i] <= mx2)) {
                    return INF;
                }
                ++result;
            }
            return result;
        };

        const int result = min(count(nums1.back(), nums2.back()), count(nums2.back(), nums1.back()));
        return result != INF ? result : -1;
    }
};
