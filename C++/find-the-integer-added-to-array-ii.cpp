// Time:  O(n)
// Space: O(n)

// partial sort, freq table
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        const auto& check = [](auto& cnt2, auto& cnt1) {
            unordered_set<int> keys;
            for (const auto& [k, _] : cnt2) {
                keys.emplace(k);
            }
            for (const auto& [k, _] : cnt1) {
                keys.emplace(k);
            }
            for (const auto& k : keys) {
                if (cnt2[k] > cnt1[k]) {
                    return false;
                }
            }
            return true;
        };

        partial_sort(begin(nums1), begin(nums1) + 3, end(nums1), greater<int>());
        unordered_map<int, int> cnt2;
        for (const auto& x : nums2) {
            ++cnt2[x];
        }
        const int mx = ranges::max(nums2);
        for (int i = 0; i < 3; ++i) {
            const int d = mx - nums1[i];
            unordered_map<int, int> cnt1;
            for (const auto& x : nums1) {
                ++cnt1[x + d];
            }
            if (check(cnt2, cnt1)) {
                return d;
            }
        }
        return -1;
    }
};

// Time:  O(n)
// Space: O(n)
// partial sort, freq table
class Solution2 {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        const auto& check = [](const auto& cnt2, const auto& cnt1) {
            for (const auto& [k, v] : cnt2) {
                if (!cnt1.count(k) || v > cnt1.at(k)) {
                    return false;
                }
            }
            return true;
        };

        const auto& topk = [](const auto& nums, int k) {  // Time: O(k * n)
            vector<int> topk(k, numeric_limits<int>::min());
            for (auto x : nums) {
                for (auto& y : topk) {
                    if (x > y) {
                        swap(x, y);
                    }
                }
            }
            return topk;
        };

        unordered_map<int, int> cnt2;
        for (const auto& x : nums2) {
            ++cnt2[x];
        }
        const int mx = ranges::max(nums2);
        for (const auto& x : topk(nums1, 3)) {
            const int d = mx - x;
            unordered_map<int, int> cnt1;
            for (const auto& x : nums1) {
                ++cnt1[x + d];
            }
            if (check(cnt2, cnt1)) {
                return d;
            }
        }
        return -1;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort
class Solution3 {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        for (int i = 0; i < 3; ++i) {
            const int d = nums2.back() - nums1[size(nums1) - 1 - i];
            int cnt = 0;
            for (int j = 0; j < size(nums2); ++j) {
                for (; j + cnt < size(nums1) && nums1[j + cnt] + d != nums2[j]; ++cnt);
            }
            if (cnt <= 2) {
                return d;
            }
        }
        return -1;
    }
};
