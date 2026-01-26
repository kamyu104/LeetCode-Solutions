// Time:  O(n)
// Space: O(n)

// array
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        const auto& rotate = [](auto& nums, int64_t k) {
            const int n = size(nums);
            k %= n;
            const auto& c = gcd(n, k);
            for (int i = 0; i < c; ++i) {
                for (int j = 1; j < n / c; ++j) {
                    swap(nums[i], nums[(((i - j * k) % n) + n) % n]);
                }
            }
        };

        vector<int> result;
        result.reserve(size(nums));
        for (const auto& x : nums) {
            if (x >= 0) {
                result.emplace_back(x);
            }
        }
        if (empty(result)) {
            return nums;
        }
        rotate(result, k);
        for (int i = 0, j = 0; i < size(nums); ++i) {
            if (nums[i] < 0) {
                continue;
            }
            nums[i] = result[j++];
        }
        return nums;
    }
};

// Time:  O(n)
// Space: O(n)
// array
class Solution2 {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        const auto& rotate = [](auto& nums, int k) {
            k %= size(nums);
            reverse(begin(nums), end(nums));
            reverse(begin(nums), begin(nums) + (size(nums) - k));
            reverse(begin(nums) + (size(nums) - k), end(nums));
        };

        vector<int> result;
        result.reserve(size(nums));
        for (const auto& x : nums) {
            if (x >= 0) {
                result.emplace_back(x);
            }
        }
        if (empty(result)) {
            return nums;
        }
        rotate(result, k);
        for (int i = 0, j = 0; i < size(nums); ++i) {
            if (nums[i] < 0) {
                continue;
            }
            nums[i] = result[j++];
        }
        return nums;
    }
};

// Time:  O(n)
// Space: O(n)
// array
class Solution3 {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> result;
        result.reserve(size(nums));
        for (const auto& x : nums) {
            if (x >= 0) {
                result.emplace_back(x);
            }
        }
        if (empty(result)) {
            return nums;
        }
        k %= size(result);
        rotate(begin(result), begin(result) + k, end(result));
        for (int i = 0, j = 0; i < size(nums); ++i) {
            if (nums[i] < 0) {
                continue;
            }
            nums[i] = result[j++];
        }
        return nums;
    }
};
