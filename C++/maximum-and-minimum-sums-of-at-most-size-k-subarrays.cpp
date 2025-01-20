// Time:  O(n)
// Space: O(k)

// two pointers, sliding window, mono deque
class Solution {
public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        const auto& count = [&](const auto& check) {
            int64_t result = 0, total = 0;
            deque<int> dq;
            for (int right = 0; right < size(nums); ++right) {
                while (!empty(dq) && !check(nums[dq.back()], nums[right])) {
                    const int i  = dq.back(); dq.pop_back();
                    const int64_t cnt = i - (!empty(dq) ? dq.back() + 1 : max(right - k + 1, 0)) + 1;
                    total -= cnt * nums[i];
                }
                const int64_t cnt = right - (!empty(dq) ? dq.back() + 1 : max(right - k + 1, 0)) + 1;
                dq.emplace_back(right);
                total += cnt * nums[right];
                result += total;
                if (right >= k - 1) {
                    total -= nums[dq[0]];
                    if (dq[0] == right - (k - 1)) {
                        dq.pop_front();
                    }
                }
            }
            return result;
        };
    
        return count([](const auto& a, const auto& b) { return a < b; }) + 
               count([](const auto& a, const auto& b) { return a > b; });
    }
};

// Time:  O(n)
// Space: O(k)
// two pointers, sliding window, mono deque
class Solution2 {
public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        const auto& count = [&](const auto& check) {
            int64_t result = 0, total = 0;
            deque<pair<int, int>> dq;
            for (int right = 0; right < size(nums); ++right) {
                int left = right;
                for (int i; !empty(dq) && !check(nums[dq.back().first], nums[right]); ) {
                    tie(i, left) = dq.back(); dq.pop_back();
                    total -= static_cast<int64_t>(i - left + 1) * nums[i];
                }
                dq.emplace_back(right, left);
                total += static_cast<int64_t>(right - left + 1) * nums[right];
                result += total;
                if (right - (k - 1) >= 0) {
                    total -= nums[dq[0].first];
                    if (dq[0].first == right - (k - 1)) {
                        dq.pop_front();
                    } else {
                        assert(dq[0].second == right - (k - 1));
                        ++dq[0].second;
                    }
                }
            }
            return result;
        };
    
        return count([](const auto& a, const auto& b) { return a < b; }) + 
               count([](const auto& a, const auto& b) { return a > b; });
    }
};
