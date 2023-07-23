// Time:  O(nlogn)
// Space: O(1)

// constructive algorithms, counting sort, greedy
class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        const auto& inplace_counting_sort = [](vector<int> *nums, bool is_reverse) {
            if (empty(*nums)) {
                return;
            }
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
        };
        
        for (auto& x : usageLimits) {
            x = min(x, static_cast<int>(size(usageLimits)));
        }
        inplace_counting_sort(&usageLimits, false);
        int result = 0;
        int64_t curr = 0;
        for (const auto& x : usageLimits) {
            curr += x;
            if (curr >= result + 1) {
                curr -= result + 1;
                ++result;
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// constructive algorithms, sort, greedy
class Solution2 {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(begin(usageLimits), end(usageLimits));
        int result = 0;
        int64_t curr = 0;
        for (const auto& x : usageLimits) {
            curr += x;
            if (curr >= result + 1) {
                curr -= result + 1;
                ++result;
            }
        }
        return result;
    }
};
