// Time:  O(logn)
// Space: O(logn)

// constructive algorithms, greedy
class Solution {
public:
    int closestFair(int n) {
        string digits = to_string(n);
        string result;
        if (size(digits) % 2 == 0) {
            int left_even = count_if(cbegin(digits), cend(digits), [](const auto& x) { return (x - '0') % 2 == 0; });
            if (left_even == size(digits) / 2) {
                return n;
            }
            for (int i = size(digits) - 1; i >= size(digits) / 2; --i) {
                if ((digits[i] - '0') % 2 == 0) {
                    --left_even;
                }
                const int left_odd = i - left_even;
                int right_even = size(digits) / 2 - left_even;
                int right_odd = size(digits) / 2 - left_odd;
                if (right_even < 0 || right_odd < 0) {
                    continue;
                }
                const char d = (right_odd == 0 && digits[i] % 2 == 0) || (right_even == 0 and digits[i] % 2 == 1) ? digits[i] + 2 : digits[i] + 1;
                if (d > '9') {
                    continue;
                }
                if ((d - '0') % 2 == 0) {
                    --right_even;
                } else {
                    --right_odd;
                }
                result.append(digits, 0, i);
                result.append(1, d);
                result.append(right_even, '0');
                result.append(right_odd, '1');
                break;
            }
        }
        if (empty(result)) {
            const int l = size(digits) / 2 + 1;
            result.append(1, '1');
            result.append(l, '0');
            result.append(l - 1, '1');
        }
        return stoi(result);
    }
};
