// Time:  O(n * (logn)^(2*logn))
// Space: O(2*logn)

// backtracking
class Solution {
public:
    int punishmentNumber(int n) {
        const function<bool(int, int)> backtracking = [&](int curr, int target) {
            if (target == 0) {
                return curr == 0;
            }
            for (int base = 10; base / 10 <= curr; base *= 10) {
                const int q = curr / base, r = curr % base;
                if (target - r < 0) {
                    break;
                }
                if (backtracking(q, target - r)) {
                    return true;
                }
            }
            return false;
        };

        int result = 0;
        for (int i = 1; i <= n; ++i) {
            if (backtracking(i * i, i)) {
                result += i * i;
            }
        }
        return result;
    }
};
