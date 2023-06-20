// Time:  O(n)
// Space: O(n)

// mono stack, difference array, prefix sum
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        const int i = distance(cbegin(nums), min_element(cbegin(nums), cend(nums)));
        rotate(begin(nums), begin(nums) + i, end(nums));
        vector<int> left(size(nums), -1), right(size(nums), size(nums));
        vector<int> stk;
        for (int i = 0; i < size(nums); ++i) {
            while (!empty(stk) && nums[stk.back()] > nums[i]) {
                right[stk.back()] = i;
                stk.pop_back();
            }
            if (!empty(stk)) {
                left[i] = stk.back();
            }
            stk.emplace_back(i);
        }
        vector<int64_t> diff2(size(nums) + 1);
        diff2[0] = (+1) * accumulate(cbegin(nums), cend(nums), 0ll);  // diff1[k] has sum((+1)*nums[i] for i in xrange(len(nums))) for k >= 0
        diff2[1] = x;                            // diff1[k] has x for k >= 1
        diff2.back() += (-1) * nums[0];          // diff1[len(nums)] has 0*nums[0]
        for (int i = 1; i < size(nums); ++i) {
            const int l = i - left[i], r = right[i] - i;
            diff2[min(l, r)] += (-1) * nums[i];  // diff1[k] has 0*nums[i] for min(l, r) <= k < max(l, r)
            diff2[max(l, r)] += (-1) * nums[i];  // diff1[k] has (-1)*nums[i] for max(l, r) <= k < l+r
            diff2[l + r] += (+1) * nums[i];      // diff1[k] has 0*nums[i] to for k >= l+r
        }
        vector<int64_t> diff1(size(diff2));
        partial_sum(cbegin(diff2), cend(diff2), begin(diff1));
        vector<int64_t> result(size(diff1));
        partial_sum(cbegin(diff1), cend(diff1), begin(result));
        return *min_element(cbegin(result), cend(result));
    }
};

// Time:  O(nlogn)
// Space: O(n)
// binary search, mono deque
class Solution2 {
public:
    long long minCost(vector<int>& nums, int x) {
        const auto& cost = [&](int k) {
            const int w = k + 1;
            int64_t result = static_cast<int64_t>(x) * k;
            deque<int> dq;
            for (int i = 0; i < size(nums) + w - 1; ++i) {
                if (!empty(dq) && i - dq.front() == w) {
                    dq.pop_front();
                }
                while (!empty(dq) && nums[dq.back() % size(nums)] >= nums[i % size(nums)]) {
                    dq.pop_back();
                }
                dq.emplace_back(i);
                if (i >= w - 1) {
                    result += nums[dq.front() % size(nums)];
                }
            }
            return result;
        };

        const auto& check = [&](int x) {
            return cost(x) <= cost(x + 1);
        };

        int left = 0, right = size(nums);
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return cost(left);
    }
};

// Time:  O(n^2)
// Space: O(n)
// brute force
class Solution3 {
public:
    long long minCost(vector<int>& nums, int x) {
        vector<int64_t> result(size(nums) + 1);
        for (int64_t k = 0; k < size(result); ++k) {
            result[k] = x * k;
        }
        for (int i = 0; i < size(nums); ++i) {
            int64_t curr = numeric_limits<int64_t>::max();
            for (int k = 0; k < size(result); ++k) {
                curr = min(curr, static_cast<int64_t>(nums[(i + k) % size(nums)]));
                result[k] += curr;
            }
        }
        return *min_element(cbegin(result), cend(result));
    }
};
