// Time:  O(logn)
// Space: O(logn)

// constructive algorithms, greedy
class Solution {
public:
    int closestFair(int n) {
        const auto& digits = to_string(n);
        string result;
        if (size(digits) % 2 == 0) {
            vector<int> left(2);
            for (const auto& d : digits) {
                ++left[(d - '0') % 2];
            }
            if (left[0] == size(digits) / 2) {
                return n;
            }
            for (int i = size(digits) - 1; i >= size(digits) / 2; --i) {
                --left[(digits[i] - '0') % 2];
                vector<int> right = {static_cast<int>(size(digits)) / 2 - left[0],
                                     static_cast<int>(size(digits)) / 2 - left[1]};
                if (any_of(cbegin(right), cend(right), [](const auto& x) { return x < 0; })) {
                    continue;
                }
                const char d = (right[((digits[i] + 1) - '0') % 2] - 1 >= 0) ? digits[i] + 1 : digits[i] + 2;
                if (d > '9') {
                    continue;
                }
                --right[(d - '0') % 2];
                result.append(digits, 0, i);
                result.append(1, d);
                result.append(right[0], '0');
                result.append(right[1], '1');
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
