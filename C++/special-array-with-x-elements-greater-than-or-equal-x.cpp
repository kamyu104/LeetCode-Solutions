// Time:  O(n)
// Space: O(1)

// counting sort solution
class Solution {
public:
    int specialArray(vector<int>& nums) {
        static const int MAX_NUM = 1000;
        vector<int> count(MAX_NUM + 1);
        for (const auto& num : nums) {
            ++count[num];
        }
        for (int n = size(nums), i = 0; i < size(count); n -= count[i++]) {
            if (i == n) {
                return i;
            }
        }
        return -1;
    }
};


// Time:  O(n)
// Space: O(1)
// binary search + counting sort solution
class Solution2 {
public:
    int specialArray(vector<int>& nums) {
        inplace_counting_sort(&nums, true);
        int left = 0, right = size(nums) - 1;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (nums[mid] <= mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left < size(nums) && nums[left] == left ? -1 : left;
    }

private:
    void inplace_counting_sort(vector<int> *nums, bool is_reverse) {
        static const int MAX_NUM = 1000;
        vector<int> count(MAX_NUM + 1);
        for (const auto& num : *nums) {
            ++count[num];
        }
        for (int i = 1; i < size(count); ++i) {
            count[i] += count[i - 1];
        }
        for (int i = size(*nums) - 1; i >= 0; --i) {  // inplace but unstable sort
	        while ((*nums)[i] >= 0) {
                --count[(*nums)[i]];
                const int j = count[(*nums)[i]];
                tie((*nums)[i], (*nums)[j]) = pair((*nums)[j], ~(*nums)[i]);
            }
        }
        for (auto& num : *nums) {
            num = ~num;  // restore values
        }
        if (is_reverse) {  // unstable sort
            reverse(begin(*nums), end(*nums));
        }
    }
};

// Time:  O(n)
// Space: O(n)
// binary search + counting sort solution
class Solution3 {
public:
    int specialArray(vector<int>& nums) {
        nums = counting_sort(nums, true);  // extra O(n) space for stable sort
        int left = 0, right = size(nums) - 1;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (nums[mid] <= mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left < size(nums) && nums[left] == left ? -1 : left;
    }

private:
    vector<int> counting_sort(const vector<int>& nums, bool is_reverse) {
        static const int MAX_NUM = 1000;
        vector<int> count(MAX_NUM + 1);
        for (const auto& num : nums) {
            ++count[num];
        }
        for (int i = 1; i < size(count); ++i) {
            count[i] += count[i - 1];
        }
        vector<int> result(size(nums));
        if (!is_reverse) {
            for (int i = size(nums) - 1; i >= 0; --i) {  // stable sort
                result[--count[nums[i]]] = nums[i];
            }
        } else {
            for (const auto& num : nums) {  // stable sort
                result[--count[num]] = num;
            }
            reverse(begin(result), end(result));
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort solution
class Solution4 {
public:
    int specialArray(vector<int>& nums) {
        sort(rbegin(nums), rend(nums));
        int i = 0;
        while (i < size(nums)) {
            if (nums[i] <= i) {
                break;
            }
            ++i;
        }
        return i < size(nums) && nums[i] == i ? -1 : i;
    }
};
