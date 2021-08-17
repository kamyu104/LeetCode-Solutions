// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const auto start = lower_bound(cbegin(nums), cend(nums), target);
        const auto end = upper_bound(cbegin(nums), cend(nums), target);
        if (start != cend(nums) && *start == target) {
            return {static_cast<int>(start - cbegin(nums)),
                    static_cast<int>(end - cbegin(nums) - 1)};
        }
        return {-1, -1};
    }
};

class Solution2 {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        const int begin = lower_bound(nums, target);
        const int end = upper_bound(nums, target);
        if (begin < size(nums) && nums[begin] == target) {
            return {begin, end - 1};
        }
        return {-1, -1};
    }

private:
    int lower_bound(const vector<int> &nums, int target) {
        int left = 0, right = size(nums) - 1;
        // Find min left s.t. A[left] >= target.
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int upper_bound(const vector<int> &nums, int target) {
        int left = 0, right = size(nums) - 1;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

class Solution3 {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        const int begin = lower_bound(nums, target);
        const int end = upper_bound(nums, target);
        if (begin < size(nums) && nums[begin] == target) {
            return {begin, end - 1};
        }
        return {-1, -1};
    }

private:
    int lower_bound(const vector<int> &nums, int target) {
        int left = 0, right = size(nums);
        // Find min left s.t. A[left] >= target.
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int upper_bound(const vector<int> &nums, int target) {
        int left = 0, right = size(nums);
        // Find min left s.t. A[left] > target.
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

class Solution4 {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        const int begin = lower_bound(nums, target);
        const int end = upper_bound(nums, target);
        if (begin < size(nums) && nums[begin] == target) {
            return {begin, end - 1};
        }
        return {-1, -1};
    }

private:
    int lower_bound(const vector<int> &nums, int target) {
        int left = -1, right = size(nums);
        // Find min left s.t. A[left] >= target.
        while (left + 1 < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }

    int upper_bound(const vector<int> &nums, int target) {
        int left = -1, right = size(nums);
        // Find min left s.t. A[left] > target.
        while (left + 1 < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};
