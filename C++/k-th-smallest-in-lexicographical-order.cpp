// Time:  O(logn)
// Space: O(logn)

class Solution {
public:
    int findKthNumber(int n, int k) {
        int result = 0;

        vector<int> cnts(10);
        for (int i = 1; i <= 9; ++i) {
            cnts[i] = cnts[i - 1] * 10 + 1;
        }

        vector<int> nums;
        for (int i = n; i > 0; i /= 10) {
            nums.emplace_back(i % 10);
        }
        int total = n;
        int target = 0;
        for (int i = nums.size() - 1; i >= 0 && k; --i) {
            target = target * 10 + nums[i];
            const auto start = i == nums.size() - 1 ? 1 : 0;
            for (int j = start; j <= 9; ++j) {
                const auto candidate = result * 10 + j;
                int num;
                if (candidate < target) {
                    num = cnts[i + 1];
                } else if (candidate > target) {
                    num = cnts[i];
                } else {
                    num = total - cnts[i + 1] * (j - start) - cnts[i] * (9 - j);
                }
                if (k > num) {
                    k -= num;
                } else {
                    result = candidate;
                    --k;
                    total = num - 1;
                    break;
                }
            }
        }
        return result;
    }
};

// Time:  O(logn * logn)
// Space: O(logn)
class Solution2 {
public:
    int findKthNumber(int n, int k) {
        int result = 0;
        int index = 0;
        findKthNumberHelper(n, k, 0, &index, &result);
        return result;
    }

private:
    bool findKthNumberHelper(int n, int k, int cur, int *index, int *result) {
        if (cur) {
            ++(*index);
            if (*index == k) {
                *result = cur;
                return true;
            }
        }
        for (int i = (cur == 0 ? 1 : 0); i <= 9; ++i, cur /= 10) {
            cur = cur * 10 + i;
            int cnt = count(n, cur);
            if (k > cnt + *index) {
                *index += cnt;
                continue;
            }
            if (cur <= n && findKthNumberHelper(n, k, cur, index, result)) {
                return true;
            }
        }
        return false;
    }

    int count(int n, long long prefix) {  // Time:  O(logn)
        int result = 0;
        int number = 1;
        while (prefix <= n) {
            result += number;
            prefix *= 10;
            number *= 10;
        }
        result -= max(number / 10 - (n - prefix / 10 + 1), static_cast<long long>(0));
        return result;
    }
};
