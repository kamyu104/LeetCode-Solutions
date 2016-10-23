// Time:  O(logn * logn)
// Space: O(logn)

class Solution {
public:
    int findKthNumber(int n, int k) {
        int result = 0;
        int cur = 0;
        int index = 0;
        for (int i = 1; i <= 9; ++i, cur /= 10) {
            cur = cur * 10 + i;
            int cnt = count(n, cur);
            if (k > cnt + index) {
                index += cnt;
                continue;
            }
            if (cur <= n && findKthNumberHelper(n, k, cur, &index, &result)) {
                break;
            }
        }
        return result;
    }

private:
    bool findKthNumberHelper(int n, int k, int cur, int *index, int *result) {
        ++(*index);
        if (*index == k) {
            *result = cur;
            return true;
        }
        for (int i = 0; i <= 9; ++i, cur /= 10) {
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
