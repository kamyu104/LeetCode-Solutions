// Time:  O(nlogn + logt)
// Space: O(1)

// lc0330
// sort, greedy
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(begin(coins), end(coins));
        int result = 0, reachable = 0;
        for (const auto& x : coins) {
            // if (x > target) {
            //     break;
            // }
            while (!(reachable >= x - 1)) {
                ++result;
                reachable += reachable + 1;
            }
            if (reachable >= target - x) {
                return result;
            }
            reachable += x;
        }
        ++result;
        for (; !(reachable >= target - (reachable + 1)); reachable += reachable + 1) {
            ++result;
        }
        return result;
    }
};

// Time:  O(nlogn + logt)
// Space: O(1)
// lc0330
// sort, greedy
class Solution2 {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(begin(coins), end(coins));
        int result = 0, reachable = 0;
        for (const auto& x : coins) {
            while (!(reachable >= x - 1)) {
                ++result;
                if (reachable >= target - (reachable + 1)) {
                    return result;
                }
                reachable += reachable + 1;
            }
            if (reachable >= target - x) {
                return result;
            }
            reachable += x;
        }
        ++result;
        for (; !(reachable >= target - (reachable + 1)); reachable += reachable + 1) {
            ++result;
        }
        return result;
    }
};
