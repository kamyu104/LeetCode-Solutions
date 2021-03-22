// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(begin(coins), end(coins));
        int result = 1;
        for (const auto& c : coins) {
            if (c > result) {
                break;
            }
            result += c;
        }
        return result;
    }
};
