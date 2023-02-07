// Time:  O(n + klogn)
// Space: O(1)

// heap
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / b;
        };

        int64_t result = 0;
        make_heap(begin(nums), end(nums));
        while (k-- && !empty(nums)) {
            int x = nums.front();
            result += x;
            pop_heap(begin(nums), end(nums)); nums.pop_back();
            const auto nx = ceil_divide(x, 3);
            if (!nx) {
                continue;
            }
            nums.emplace_back(nx);
            push_heap(begin(nums), end(nums));
        }
        return result;
    }
};

// Time:  O(n + klogn)
// Space: O(1)
// heap
class Solution2 {
public:
    long long maxKelements(vector<int>& nums, int k) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / b;
        };

        int64_t result = 0;
        make_heap(begin(nums), end(nums));
        while (--k >= 0) {
            int x = nums.front();
            result += x;
            pop_heap(begin(nums), end(nums)); nums.pop_back();
            nums.emplace_back(ceil_divide(x, 3));
            push_heap(begin(nums), end(nums));
        }
        return result;
    }
};

