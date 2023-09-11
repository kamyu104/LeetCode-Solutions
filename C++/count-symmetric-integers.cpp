// Time:  O(rlogr)
// Space: O(r)

// brute force, memoization
static const int MAX_R = 10000;
vector<int> LOOKUP(MAX_R, -1);
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        const auto& check = [](int x) {
            if (LOOKUP[x - 1] == -1) {
                const auto& digits = to_string(x);
                if (size(digits) % 2) {
                    LOOKUP[x - 1] = 0;
                } else {
                    int curr1 = 0;
                    for (int i = 0; i < size(digits) / 2; ++i) {
                        curr1 += digits[i] - '0';
                    }
                    int curr2 = 0;
                    for (int i = size(digits) / 2; i < size(digits); ++i) {
                        curr2 += digits[i] - '0';
                    }
                    LOOKUP[x - 1] = curr1 == curr2 ? 1 : 0;
                }
            }
            return LOOKUP[x - 1];
        };

        int result = 0;
        for (int i = low; i <= high; ++i) {
            result += check(i);
        }
        return result;
    }  
};
