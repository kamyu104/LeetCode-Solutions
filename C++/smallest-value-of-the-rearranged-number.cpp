// Time:  O(d), d is the number of digits
// Space: O(d)

// greedy, counting sort
class Solution {
public:
    long long smallestNumber(long long num) {
        int64_t sign = (num >= 0) ? 1 : -1;
        string nums = to_string(abs(num));
        inplace_counting_sort(&nums, sign == -1);
        auto it = find_if(begin(nums), end(nums), [](const auto& x) {
            return x != '0';
        });
        if (it != end(nums)) {
            swap(nums[0], *it);
        }
        return sign * stoll(nums);
    }

private:
    void inplace_counting_sort(string *nums, bool is_reverse) {
        const int max_num = *max_element(cbegin(*nums), cend(*nums));
        vector<int> count(max_num + 1);
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

// Time:  O(dlogd), d is the number of digits
// Space: O(d)
// greedy
class Solution2 {
public:
    long long smallestNumber(long long num) {
        int64_t sign = (num >= 0) ? 1 : -1;
        string nums = to_string(abs(num));
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
