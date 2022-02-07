// Time:  O(logn)
// Space: O(logn)

// greedy
class Solution {
public:
    long long smallestNumber(long long num) {
        int64_t sign = (num >= 0) ? 1 : -1;
        if (num < 0) {
            num = -num;
        }
        string nums = to_string(num);
        if (sign == 1) {
            sort(begin(nums), end(nums));
        } else {
            sort(rbegin(nums), rend(nums));
        }
        auto it = find_if(begin(nums), end(nums), [](const auto& x) {
            return x != '0';
        });
        if (it != end(nums)) {
            swap(nums[0], *it);
        }
        return sign * stoll(nums);
    }
};
