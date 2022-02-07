// Time:  O(n)
// Space: O(c), c is the max of nums

// counting sort, inplace solution
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        const auto& partition = [](const auto& index, vector<int> *nums) {
            for (int i = 0; i < size(*nums); ++i) {
                int j = i;
                while ((*nums)[i] >= 0) {
                    j = index(j);
                    tie((*nums)[i], (*nums)[j]) = pair((*nums)[j], ~(*nums)[i]);
                }
            }
            for (auto& x : (*nums)) {
                x = ~x;  // restored
            }
        };
        partition([&nums](int i) {
            return (i % 2 == 0) ? i / 2 : (static_cast<int>(size(nums)) + 1) / 2 + i / 2;
        }, &nums);
        inplace_counting_sort(&nums, 0, (size(nums) + 1) / 2 - 1, false);
        inplace_counting_sort(&nums, (size(nums) + 1) / 2, size(nums) - 1, true);
        partition([&nums](int i) {
            return (i < (size(nums) + 1) / 2) ? 2 * i : 1 + 2 * (i - (size(nums) + 1) / 2);
        }, &nums);
        return nums;
    }

private:
    void inplace_counting_sort(vector<int> *nums, int left, int right, bool is_reverse) {
        if (right - left + 1 == 0) {
            return;
        }
        const int max_num = *max_element(cbegin(*nums) + left, cbegin(*nums) + right + 1);
        vector<int> count(max_num + 1);
        for (int i = left; i <= right; ++i) {
            ++count[(*nums)[i]];
        }
        for (int i = 1; i < size(count); ++i) {
            count[i] += count[i - 1];
        }
        for (int i = right; i >= left; --i) {  // inplace but unstable sort
            while ((*nums)[i] >= 0) {
                --count[(*nums)[i]];
                const int j = left + count[(*nums)[i]];
                tie((*nums)[i], (*nums)[j]) = pair((*nums)[j], ~(*nums)[i]);
            }
        }
        for (int i = left; i <= right; ++i) {
            (*nums)[i] = ~(*nums)[i];  // restore values
        }
        if (is_reverse) {  // unstable sort
            reverse(begin(*nums) + left, begin(*nums) + right + 1);
        }
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort, inplace solution
class Solution2 {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        const auto& partition = [](const auto& index, vector<int> *nums) {
            for (int i = 0; i < size(*nums); ++i) {
                int j = i;
                while ((*nums)[i] >= 0) {
                    j = index(j);
                    tie((*nums)[i], (*nums)[j]) = pair((*nums)[j], ~(*nums)[i]);
                }
            }
            for (auto& x : (*nums)) {
                x = ~x;  // restore values
            }
        };
        partition([&nums](int i) {
            return (i % 2 == 0) ? i / 2 : (static_cast<int>(size(nums)) + 1) / 2 + i / 2;
        }, &nums);
        sort(begin(nums), begin(nums) + (size(nums) + 1) / 2);
        sort(begin(nums) + (size(nums) + 1) / 2, end(nums), greater<int>());
        partition([&nums](int i) {
            return (i < (size(nums) + 1) / 2) ? 2 * i : 1 + 2 * (i - (size(nums) + 1) / 2);
        }, &nums);
        return nums;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort
class Solution3 {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even, odd;
        for (int i = 0; i < size(nums); ++i) {
            if (i % 2 == 0) {
                even.emplace_back(nums[i]);
            } else {
                odd.emplace_back(nums[i]);
            }
        }
        sort(begin(even), end(even));
        sort(rbegin(odd), rend(odd));
        vector<int> result(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            if (i % 2 == 0) {
                result[i] = even[i / 2];
            } else {
                result[i] = odd[i / 2];
            }
        }
        return result;
    }
};
