// Time:  O(logn)
// Space: O(1)

// greedy
class Solution {
public:
    int minMaxDifference(int num) {
        const auto& f = [&](int dst) {
            int result = 0, base = 1;
            for (; base <= num; base *= 10);
            base /= 10;
            for (int src = -1; base; base /= 10) {
                const int d = num / base % 10;
                if (src == -1 && d != dst) {
                    src = d;
                }
                result += base * (d == src ? dst : d);
            }
            return result;
        };

        return f(9) - f(0);
    }
};
