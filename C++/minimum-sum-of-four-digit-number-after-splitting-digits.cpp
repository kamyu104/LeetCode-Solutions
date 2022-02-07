// Time:  O(d) = O(1), d is the number of digits
// Space: O(d) = O(1)

// greedy
class Solution {
public:
    int minimumSum(int num) {
        vector<int> nums;
        for (; num; num /= 10) {
            nums.emplace_back(num % 10);
        }
        inplace_counting_sort(&nums, false);
        int a = 0, b = 0;
        for (const auto& x: nums) {
            a = a * 10 + x;
            swap(a, b);
        }
        return a + b;
    }

private:
    void inplace_counting_sort(vector<int> *nums, bool is_reverse) {
        const int max_num = *max_element(cbegin(*nums), cend(*nums));
        vector<int> count(max_num + 1);
        for (const auto& num : *nums) {
            ++count[num];
        }
        for (int i = 1; i < size(count); ++i) {
            count[i] += count[i - 1];
        }
        vector<int> result(size(*nums));
        for (int i = size(*nums) - 1; i >= 0; --i) {  // inplace but unstable sort
            if ((*nums)[i] < 0) {  // processed
                continue;
            }
            while (i != count[(*nums)[i]] - 1) {
                --count[(*nums)[i]];
                tie((*nums)[count[(*nums)[i]]], (*nums)[i]) = pair(~(*nums)[i], (*nums)[count[(*nums)[i]]]);
            }
            --count[(*nums)[i]];
            (*nums)[i] = ~(*nums)[i];
        }
        for (auto& num : *nums) {
            num = ~num;  // restore values
        }
        if (is_reverse) {  // unstable sort
            reverse(begin(*nums), end(*nums));
        }
    }
};

// Time:  O(dlogd) = O(1), d is the number of digits
// Space: O(d) = O(1)
// greedy
class Solution2 {
public:
    int minimumSum(int num) {
        vector<int> nums;
        for (; num; num /= 10) {
            nums.emplace_back(num % 10);
        }
        sort(begin(nums), end(nums));
        int a = 0, b = 0;
        for (const auto& x: nums) {
            a = a * 10 + x;
            swap(a, b);
        }
        return a + b;
    }
};

