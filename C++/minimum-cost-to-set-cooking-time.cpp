// Time:  O(1)
// Space: O(1)

// simulation
class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        const auto& cost = [=](int m, int s) {
            if (!(0 <= m && m <= 99 && s <= 99)) {
                return numeric_limits<int>::max();
            }
            int result = 0, curr = startAt;
            for (const auto& x: to_string(m * 100 + s)) {
                result += (((x - '0') != curr) ? moveCost : 0) + pushCost;
                curr = x - '0';
            }
            return result;
        };
        int m = targetSeconds / 60, s = targetSeconds % 60;
        return min(cost(m, s), cost(m - 1, s + 60));
    }
};
